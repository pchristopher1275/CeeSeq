#!/usr/bin/perl
use strict;
my $gVerbose = 1;
my $gSourceDir = "source/cseqHub/cseqHub/";
my $gInstallLocation = "/Users/pete/Documents/Max 7/Packages/CeeSeq/";

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
    for my $a (@ARGV) {
        if ($a =~ /^-(.)(.*)/) {
            my $x = $2;
            $x = 1 unless length($x) > 0;
            $opts{$1} = $x;
        } else {
            push @args, $a;
        }
    }
    return \@args, \%opts;
}

sub xcodebuild {
    my ($buildNumber) = @_;
    my $cmd = "(cd $gSourceDir && xcodebuild  GCC_PREPROCESSOR_DEFINITIONS='CSEQ_BUILD_NUMBER=$buildNumber')";
    run($cmd);
}

sub findBuildNumber {
    my @lines = backtick "ls externals/";
    chomp(@lines);
    my $largest = 0;
    for my $line (@lines) {
        my ($index) = ($line =~ /cseqHub(\d+)\.mxo/);
        #print "$line: ", (defined($index) ? "YES" : "no"), "\n"; 
        next unless defined($index);
        if ($largest < $index) {
            $largest = $index;
        }
    }
    $largest++;    
    return $largest;
}

my ($args, $opts) = argsAndOpts();
my $buildNumber = findBuildNumber();
if ($opts->{p}) {
    $buildNumber = 0;
}
xcodebuild($buildNumber);
if ($buildNumber != 0) {
    run "rm -rf '$gInstallLocation/externals/cseqHub${buildNumber}.mxo'", noexit=>1;
    run "cp -rf externals/cseqHub.mxo '$gInstallLocation/externals/cseqHub${buildNumber}.mxo'";
} else {
    run "rm -rf '$gInstallLocation/externals/cseqHub.mxo'", noexit=>1;
    run "cp -rf externals/cseqHub.mxo '$gInstallLocation/externals/cseqHub.mxo'";
}


