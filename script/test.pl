#!/usr/bin/perl
use strict;
my $gVerbose = 1;

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
            $tests{$test} = 1;
        }
    }
    return (\%files, \%tests);
}
sub compile {
    my ($file) = @_;
}
sub main {
    my ($args, $opts)          = argsAndOpts();
    my ($testFiles, $testTags) = testsAndFiles();
    my @tagsAndFiles = @$args;
    if (@tagsAndFiles > 0) {

    }

    my $noArgs        = @$args > 0 ? 0 : 1;
    if ($noArgs || buildTagPresent($args, "port")) {
        portSetGlobals();
        build($opts);
    }
    if ($noArgs || buildTagPresent($args, "cseq")) {
        cseqHubSetGlobals();
        build($opts);
    }
}

main();
