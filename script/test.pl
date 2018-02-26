#!/usr/bin/perl
use strict;
my $gVerbose = 1;
my $gTestDir  = "test";
my $gBuildDir = "$gTestDir/build";

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

my %legitArgs = (
    create => 1,
    test => 1,
);

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
    for my $a (@args) {
        die "Unknown argument tag '$a'" unless $legitArgs{$a};
    }


    return \@args, \%opts;
}

sub mkBuildDir {
    run "mkdir -p $gTestDir";
}

sub xcodebuild {
    my ($buildNumber) = @_;
    my $cmd = "(cd $gSourceDir && xcodebuild  GCC_PREPROCESSOR_DEFINITIONS='CSEQ_BUILD_NUMBER=$buildNumber')";
    run($cmd);
}

sub listOfTestFiles {
    my @lines = backtick "ls test/*.c";
    my @fileNames;
    for my $line (@lines) {
        $line =~ s[^test/][];
        $line =~ s/\.c$//;
        push @fileNames, $line;
    }
    return \@fileNames;
}

sub testsForFile {
    my ($file) = @_;
    $file = "test/$file.c";
    open my $fd, $file or die "Failed to open $file";
    my %tests;
    while (<$fd>) {
        next unless /Unit_test\((.*)\)/;
        my $name = $1;
        $name =~ s/\s*//g;
        $tests{$name} = 1;
    }
    close($fd);
    return [sort {$a cmp $b} keys(%tests)];
}

sub testsForAllFiles {
    my @files = listOfTestFiles();
    my %tests;
    for my $file (@files) {
        %tests{$file} = {};
        my %subhash;
        my $testsOfFile = testsForFile($file);
        for my $t (@$testsOfFile) {
            $subhash{$t} = 1;
        }
        $tests{$file} = \%subhash;
    }
    return %tests;
}

sub testsAndFiles {
    my %t = testsForAllFiles();
    my %files;
    my %tests;
    for my $file (keys(%t)) {
        $files{$file} = 1;
        for my $test (keys(%{$t{$file}})) {
            my $subarr = $tests{$test};
            $subarr = [] unless defined($subarr);
            push @$subarr, $file;
            $tests{$test} = subarr;
        }
    }
    return (\%files, \%tests);
}

sub exeFromSource {
    my ($file) = @_;
    my ($exe) = ($file =~ m[/([^/]+)\.c]);
    die "Failed to find exe directory from file $file" unless defined($exe);
    return $exe;
}

sub compile {
    my ($file) = @_;
    my $exe = exeFromSource($file);
    print "Compiling $file\n";
    my $cmd = "gcc -o $gBuildDir/$exe $file";
    return system $cmd;
}

sub runTests {
    my ($file, $tags) = @_;
    $tags = [] unless defined($tags);
    my $arg = join(" ", @$tags);
    my $exe = exeFromSource($file);
    return system "$exe $arg";
}

sub main {
    my ($args, $opts)          = argsAndOpts();
    my ($testFiles, $testTags) = testsAndFiles();
    my @argFiles;
    my @argTags;
    if (@$args > 0) {
        for my $arg (@$args) {
            if ($testFiles->{$arg}) {
                push @argFiles, $arg;
            } else if ($testTags->{$arg}) {
                push @argTags, $arg;
            } else {
                die "Failed to identify argument $arg"
            }
        }
    } else {
        @argFiles = keys(%$testFiles);
    }

    my %filesRun;
    for my $file (@argFiles) {
        compile($file) && die "Failed to compile $file";
        runTests($file);
        $filesRun{$file} = 1;
    }

    my %file2TagArguments;
    for my $tag (@argTags) {
        my $filesWithTag = $testTags->{$tag};
        for my $file (@$filesWithTag) {
            next if $filesRun{$file};
            my $arg = $file2TagArguments{$file};
            $arg  = "" unless defined($arg);
            $arg .= "$tag "
            $file2TagArguments{$file} = $arg;
        }
    }

    for my $file (keys(%file2TagArguments)) {
        compile($file) && die "Failed to compile $file";
        runTests($file, $file2TagArguments{$file});
    }
}

main();
