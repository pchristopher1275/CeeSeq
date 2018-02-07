#!/usr/bin/perl
use strict;
my $gVerbose = 1;
my $gBinary = "../Shared/bcpp-20150811/code/bcpp";
sub run {
    my ($cmd) = @_;
    print "$cmd\n" if $gVerbose;
    if (system $cmd) {
        die "Failed '$cmd'";
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

sub format_source {
   my @files = backtick("find source/cseq -name '*.c'");
   push @files, backtick("find source/cseqHub -name '*.c'");
   chomp(@files);
   for my $file (@files) {
	run("$gBinary -fnc bcpp.cfg $file $file.format");
	run("mv $file.format $file");
   }
}

format_source();
