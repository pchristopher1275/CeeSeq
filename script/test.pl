#!/usr/bin/perl
use Data::Dumper;

use strict;
my $gVerbose = 1;
my $gHome     = "$ENV{HOME}/CeeSeq";
my $gTestDir  = "$gHome/test";
my $gBuildDir = "$gTestDir/build";

sub dumper {
    print Dumper($_[0]), "\n";
}

sub run {
    my ($cmd, %opts) = @_;
    print "$cmd\n" if $gVerbose;
    if (system $cmd) {
        die "Failed '$cmd'" unless $opts{noexit};
    }
}

sub backtick {
    my ($cmd) = @_;
    if (wantarray) {
        my @a = `$cmd`;
        if ($?) {
            die "Failed '$cmd'";
        }
        return @a;
    } else {
        my $buffer = `$cmd`;
        if ($?) {
            die "Failed '$cmd'";
        }
        return $buffer;
    }
}

sub argsAndOpts {
    my @args;
    my %opts;
    for my $arg (@ARGV) {
        my ($o, $a) = ($arg =~ /^-(.)(.*)/);
        if (defined($o)) {
            $a = 1 unless length($a) > 0;
            $opts{$o} = $a;
        } else {
            push @args, $arg;            
        }
    }

    if (@args < 1) {
        die "Failed to specify a command to run";
    }
    my $command = shift @args;
    return $command, \@args, \%opts;
}

sub mkBuildDir {
    run "mkdir -p $gBuildDir";
}

sub listOfTestFiles {
    my @lines = backtick "ls test/t*.c";
    my @fileNames;
    for my $line (@lines) {
        next if /\.in\.c/;
        $line =~ s[^\s*][];
        $line =~ s[\s*$][];
        push @fileNames, $line;
    }
    return @fileNames;
}

sub testsForFile {
    my ($file, $supressDoubleCheck) = @_;
    open my $fd, $file or die "Failed to open $file";
    my %tests;
    my %doubleCheck;
    while (<$fd>) {
        if (/Unit_declare\((.*)\)/) {
            my $name = $1;
            $name =~ s/\s*//g;
            $tests{$name} = 1;
        } elsif (/Unit_test\((.*)\)/) {
            my $name = $1;
            $name =~ s/\s*//g;
            $doubleCheck{$name} = 1;
        }
    }
    close($fd);

    my $err = 0;
    if (!$supressDoubleCheck) {
        my @notInTests;
        my @notInDoubleCheck;
        for my $key (keys(%doubleCheck)) {
            if (!$tests{$key}) {
                push @notInTests, $key;
            }
        }
        for my $key (keys(%tests)) {
            if (!$doubleCheck{$key}) {
                push @notInDoubleCheck, $key;
            }
        }

        @notInTests       = sort {$a cmp $b} @notInTests;
        @notInDoubleCheck = sort {$a cmp $b} @notInDoubleCheck;

        if (@notInDoubleCheck) {
            print "There are missing Unit_test calls in $file:\n";
            for my $t (@notInDoubleCheck) {
                print "    Unit_test($t);\n"
            }
            $err = 1;
        }
        if (@notInTests) {
            print "There are unmatched Unit_test calls in $file:\n";
            for my $t (@notInTests) {
                print "    Unit_declare($t)\n"
            }   
            $err = 1;
        }
    }


    return $err, sort {$a cmp $b} keys(%tests);
}


sub baseFromSource {
    my ($file) = @_;
    my ($exe) = ($file =~ m[/([^/]+)\.c]);
    die "Failed to compute base for file '$file'" unless defined($exe);
    return $exe;
}

sub collectTagsAndFiles {
    my (%opts) = @_;
    my @files = listOfTestFiles();
    my %file2Tests;
    my $inconsistent = 0;
    for my $file (@files) {
        $file2Tests{$file} = {};
        my %subhash;
        my ($error, @testsOfFile) = testsForFile($file, $opts{noDoubleCheck});
        $inconsistent = 1 if $error;
        for my $test (@testsOfFile) {
            $subhash{$test} = 1;
        }
        $file2Tests{$file} = \%subhash;
    }
    if (!$opts{noDoubleCheck} && $inconsistent) {
        die "Double check failed: run with -f to supress this warning";
    }

    my %spec;
    for my $file (keys(%file2Tests)) {
        my $base = baseFromSource($file);
        $spec{$base} = {file=>$file, base=>$base, tests=>$file2Tests{$file}};
    }
    return %spec;
}

sub filterSpecByFilesAndTests {
    my ($spec, $bases, $tests) = @_;
    
    ## Add any file that is explicitly listed.
    my %nspec;
    for my $base (keys(%$spec)) {
        if ($bases->{$base}) {
            my $file = $spec->{$base}{file};
            $nspec{$base} = {base=>$base, file=>$file};
        }
    }    

    ## Add any file that has any tags that are requested.
    for my $base (keys(%$spec)) {
        my $specEntry = $nspec{$base};
        next if defined($specEntry);
        $specEntry = $spec->{$base};
        my %ntests;
        for my $test (keys(%{$specEntry->{tests}})) {
            $ntests{$test} = 1 if ($tests->{$test});
        }  
        if (%ntests > 0) {
            my $file = $spec->{$base}{file};
            $nspec{$base} = {base=>$base, file=>$file, tests=>\%ntests};   
        }
    }

    return %nspec;
}

sub compile {
    my ($specEntry) = @_;
    print "Compiling $specEntry->{file}\n";
    my $exe = "$gBuildDir/$specEntry->{base}";
    $specEntry->{exe} = $exe;

    my $file = $specEntry->{file};
    my $cmd  = "gcc -g -DTEST_BUILD -DCSEQ_HOME='\"$gHome\"' -o $exe $file";
    return system $cmd;
}

sub runTests {
    my ($specEntry, $backtrace) = @_;
    my $exe   = $specEntry->{exe};
    my $tests = $specEntry->{tests};
    $tests = {} unless defined($tests);
    my $arg = join(" ", keys(%$tests));
    if ($backtrace) {
        return system "bash -c 'lldb -s <(echo run $arg; echo bt; echo exit) $exe'";
    } else {
        return system "$exe $arg";
    }
}

sub matchFile {
    my ($commandLineFile, $path) = @_;
    return ($path =~ /$commandLineFile/);
}

sub Coverage_new {
    my ($srcDirs) = @_;
    my $self = {itype=>"Coverage", directory=>"test/coverage"};
    if (!-d $self->{directory}) {
        run "mkdir $self->{directory}";
    }
    run "rm -rf $self->{directory}/*";
    my @srcFiles;
    for my $dir (@$srcDirs) {
        my @lines = backtick "ls $dir/*.c";
        for my $line (@lines) {
            chomp($line);
            push @srcFiles, $line;
        }
    }

    $self->{srcFiles} = \@srcFiles;
    return $self;
}

sub Coverage_readCoverFile {
    my ($self, $filename, $coveredHash) = @_;
    open(my $fd, $filename) or die "Failed to open $filename";

    while (<$fd>) {
        my ($file, $line) = split " ", $_;

        if ($file eq '*totalSize') {
            if (!defined($self->{totalSize})) {
                $self->{totalSize} = $line;
            } else {
                die "inconsistent totalSize in $file" unless $self->{totalSize} == $line;
            }
        } else {
            my $subhash = $coveredHash->{$file};
            if (!defined($subhash)) {
                $subhash = {};
                $coveredHash->{$file} = $subhash;
            }
            $subhash->{$line} = 1;
        }
    }
    close($fd);
}

sub Coverage_readTouchedAndTried {
    my ($self) = @_;
    my @touchedFiles = backtick "ls $self->{directory}/*.touched";
    my @triedFiles   = backtick "ls $self->{directory}/*.tried";
    $self->{touched} = {};
    $self->{tried}   = {};
    for my $file (@touchedFiles) {
        Coverage_readCoverFile($self, $file, $self->{touched});
    }
    for my $file (@triedFiles) {
        Coverage_readCoverFile($self, $file, $self->{tried});
    }
}

my $Coverage_bgRed   = 124;
my $Coverage_bgGreen = 22;
my $Coverage_fgWhite = 255;

sub Coverage_colorizeLine {
    my ($self, $out, $text, $touched) = @_;
    my $fgColorCode = $Coverage_fgWhite;
    my $bgColorCode = $touched ? $Coverage_bgGreen : $Coverage_bgRed;
    print {$out} "\e[38;5;${fgColorCode}m\e[48;5;${bgColorCode}m${text}\e[0m\n";
}

sub Coverage_copyFile {
    my ($self, $triedSubhash, $touchedSubhash, $srcFilePath, $dstFilePath) = @_;
    open my $inp, $srcFilePath or die "Failed to open $srcFilePath";
    open my $out, ">", $dstFilePath or die "Failed to open $dstFilePath";
    my $line = 0;
    while (<$inp>) {
        $line++;
        if ($triedSubhash->{$line}) {
            chomp;
            Coverage_colorizeLine($self, $out, $_, $touchedSubhash->{$line});
        } else {
            print {$out} $_;       
        }
    }
    close($inp);
    close($out);
}

sub Coverage_copyAllFiles {
    my ($self) = @_;
    my $directory    = $self->{directory};
    my $touched      = $self->{touched};
    my $tried        = $self->{tried};
    my %expBasenames = map {$_ => 1} keys(%$tried);
    
    for my $srcFilePath (@{$self->{srcFiles}}) {
        my ($basename) = ($srcFilePath =~ m{([^/]+)$});
        die "INTERNAL ERROR" unless defined($basename);
        next unless $expBasenames{$basename};
        my $dstFilePath = "$directory/$basename";
        Coverage_copyFile($self, $tried->{$basename}, $touched->{$basename} || {}, $srcFilePath, $dstFilePath);
        delete($expBasenames{$basename});    
    }
    if (%expBasenames) {
        my $bn = join(" ", keys(%expBasenames));
        die "Some source files where NOT found: $bn";
    }
}

sub main {
    my ($command, $args, $clineOpts) = argsAndOpts();
    if ($command eq 'create') {
        die "create is unimplemented";
    } elsif ($command ne 'test') {
        die "Unknown command '$command'";
    }
    my %opts = (noDoubleCheck => $clineOpts->{f}, runInDebugger=>$clineOpts->{d});


    my @srcDirs = qw/ src test/;
    my $coverage = $clineOpts->{c} ? Coverage_new(\@srcDirs) : undef;

    ## Generate the application
    my $cover = defined($coverage) ? "-c" : "";
    run "script/generate.pl $cover -a -g test/application.c @srcDirs";

    my %spec = collectTagsAndFiles(%opts);
    
    my %allTests;
    for my $base (keys(%spec)) {
        for my $test (keys(%{$spec{$base}{tests}})) {
            $allTests{$test} = 1;
        }
    }

    my %argBases;
    my %argTests;
    if (@$args > 0) {
        for my $arg (@$args) {
            if ($spec{$arg}) {
                $argBases{$arg} = 1;
            } elsif ($allTests{$arg}) {
                $argTests{$arg} = 1;
            } else {
                die "Failed to identify argument as a test or a file $arg"
            }
        }
    } else {
        for my $base (keys(%spec)) {
            $argBases{$base} = 1;
        
        }
    }

    %spec = filterSpecByFilesAndTests(\%spec, \%argBases, \%argTests);

    ## Compile the executables
    mkBuildDir();
    for my $base (keys(%spec)) {
        compile($spec{$base}) && die "Failed to compile $spec{$base}{file}";
    }

    ## Run tests
    print "\n";
    my $status = 0;
    for my $base (keys(%spec)) {
        if (runTests($spec{$base}, $opts{runInDebugger})) {
            $status = 1;
        }
    }
    
    if (defined($coverage)) {
        Coverage_readTouchedAndTried($coverage);
        Coverage_copyAllFiles($coverage);
    }

    print "THERE WHERE TEST FAILS!!!\n" if $status;
    exit($status);
}

main();
