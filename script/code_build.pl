#!/usr/bin/perl
use strict;
my $gVerbose         = 1;
my $gHome            = "$ENV{HOME}/CeeSeq";
my $gSourceDir;
my $gCodeDir;
my $gExternalSource;
my $gExternalDest;
my $gMxoBaseName;

sub cseqHubSetGlobals { 
    $gSourceDir       = "$gHome/CeeSequencer/source/Hub/Hub";
    $gCodeDir         = "$gHome/src";
    $gExternalSource  = "$gHome/CeeSequencer/externals";
    $gExternalDest    = "$ENV{HOME}/Documents/Max 7/Packages/CeeSeq/externals";
    $gMxoBaseName     = "Hub";    
}

sub portSetGlobals {
    $gSourceDir       = "$gHome/Port/source/Port/Port";
    $gCodeDir         = "$gHome/src";
    $gExternalSource  = "$gHome/Port/externals";
    $gExternalDest    = "$ENV{HOME}/Documents/Max 7/Packages/CeeSeq/externals";
    $gMxoBaseName     = "Port";    
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

    my %ok = ('port' => 1, 'cseq' => 1);
    for my $a (@args) {
        die "Unknown argument tag '$a'" unless $ok{$a};
    }


    return \@args, \%opts;
}

sub listHandCFiles {
    my ($srcDir) = @_;
    $srcDir =~ s[/$][];
    my @lines = backtick "ls $srcDir/*";
    my @files;
    for my $line (@lines) {
        $line =~ s/^\s*//;
        $line =~ s/\s*$//;
        next unless $line =~ /[hc]$/;
        next if $line =~ /\.in.h$/ || $line =~ /\.in\.c$/;
        push @files, $line;
    }

    return \@files;
}

sub copyCodeToSource {
    my $files = listHandCFiles("src");
    my @files = @$files;
    run "cp @files $gSourceDir";
}

sub xcodebuild {
    my ($buildNumber) = @_;
    my $cmd = "(cd $gSourceDir && xcodebuild OTHER_CFLAGS='-Xclang -std=c11 -Xclang -Wint-conversion -DCSEQ_BUILD_NUMBER=$buildNumber -DCSEQ_HOME=\"\\\"$gHome\\\"\"')";
    run($cmd);
}

sub buildHeaders {
    run "$gHome/script/generate.pl src";
}

sub findBuildNumber {
    my @lines = backtick "ls '$gExternalDest'";
    chomp(@lines);
    my $largest = 0;
    for my $line (@lines) {
        my ($index) = ($line =~ /$gMxoBaseName(\d+)\.mxo/);
        next unless defined($index);
        if ($largest < $index) {
            $largest = $index;
        }
    }
    $largest++;    
    return $largest;
}

sub buildTagPresent {
    my ($lst, $tag) = @_;
    for my $t (@$lst) {
        if ($t eq $tag) {
            return 1;
        }
    }
    return 0;
}

sub build {
    my ($opts) = @_;
    my $buildNumber = findBuildNumber();
    if ($opts->{p}) {
        $buildNumber = 0;
    }

    copyCodeToSource();
    xcodebuild($buildNumber);
    if ($buildNumber != 0) {
        run "rm -rf '$gExternalDest/$gMxoBaseName${buildNumber}.mxo'", noexit=>1;
        run "cp -rf  $gExternalSource/$gMxoBaseName.mxo '$gExternalDest/$gMxoBaseName${buildNumber}.mxo'";
    } else {
        run "rm -rf '$gExternalDest/$gMxoBaseName.mxo'", noexit=>1;
        run "cp -rf  $gExternalSource/$gMxoBaseName.mxo '$gExternalDest'";
    }
}

sub main {
    my ($args, $opts) = argsAndOpts();
    my $noArgs        = @$args > 0 ? 0 : 1;
    buildHeaders();
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
