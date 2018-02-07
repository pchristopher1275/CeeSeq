#!/usr/bin/perl
use strict;
my $gVerbose = 1;
my $gPackages = "$ENV{HOME}/Documents/Max 7/Packages";
my $gBcppCfg  = "Shared/bcpp.cfg";
my $gBinary   = "Shared/bcpp-20150811/code/bcpp";
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
  chdir($gPackages) or die "Failed to chdir into $gPackages";
  my @files = backtick("find Shared/cseq/ -name '*.c'");
  push @files, backtick("find CeeSequencer/source/cseqHub/ -name '*.c'");
  push @files, backtick("find Port/source/Port/ -name '*.c'");
  chomp(@files);
  for my $file (@files) {
    	run("$gBinary -fnc '$gBcppCfg' '$file' '$file'.format");
    	run("mv '$file'.format '$file'");
  }
}

format_source();
