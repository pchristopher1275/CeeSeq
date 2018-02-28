#!/usr/bin/perl
use Data::Dumper;

use strict;
my $gVerbose = 1;
my $gTestDir  = "test";
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
    my @lines = backtick "ls test/*.c";
    my @fileNames;
    for my $line (@lines) {
        $line =~ s[^\s*][];
        $line =~ s[\s*$][];
        push @fileNames, $line;
    }
    return @fileNames;
}

sub testsForFile {
    my ($file) = @_;
    open my $fd, $file or die "Failed to open $file";
    my %tests;
    while (<$fd>) {
        next unless /Unit_declare\((.*)\)/;
        my $name = $1;
        $name =~ s/\s*//g;
        $tests{$name} = 1;
    }
    close($fd);
    return sort {$a cmp $b} keys(%tests);
}


sub baseFromSource {
    my ($file) = @_;
    my ($exe) = ($file =~ m[/([^/]+)\.c]);
    die "Failed to compute base for file '$file'" unless defined($exe);
    return $exe;
}

sub collectTagsAndFiles {
    my @files = listOfTestFiles();
    my %file2Tests;
    for my $file (@files) {
        $file2Tests{$file} = {};
        my %subhash;
        my @testsOfFile = testsForFile($file);
        for my $test (@testsOfFile) {
            $subhash{$test} = 1;
        }
        $file2Tests{$file} = \%subhash;
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
    my $cmd  = "gcc -DTEST_BUILD -o $exe $file";
    
    return system $cmd;
}

sub runTests {
    my ($specEntry) = @_;
    my $exe   = $specEntry->{exe};
    my $tests = $specEntry->{tests};
    $tests = {} unless defined($tests);
    my $arg = join(" ", keys(%$tests));
    return system "$exe $arg";
}

sub matchFile {
    my ($commandLineFile, $path) = @_;
    return ($path =~ /$commandLineFile/);
}



sub main {
    my ($command, $args, $opts) = argsAndOpts();
    if ($command eq 'create') {
        die "create is unimplemented";
    } elsif ($command ne 'test') {
        die "Unknown command '$command'";
    }

    my %spec          = collectTagsAndFiles();
    
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
        if (runTests($spec{$base})) {
            $status = 1;
        }
    }
    print "THERE WHERE TEST FAILS!!!\n" if $status;
    exit($status);
}

main();
