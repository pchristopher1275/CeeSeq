#!/usr/bin/perl
use strict;
use Data::Dumper;

my $gDirectory = "test/coverage";

sub basenames {
	my (@files) = @_;
	return map {m{([^/]+)$}} @files;
}

sub main {
	my @baseFiles = basenames(@ARGV);
	my @coverFiles = map {"$gDirectory/$_"} @baseFiles;
	for (@coverFiles) {
		die "Failed to find cover file $_" unless -f $_;
	}
	system "less -rN @coverFiles";
}

main();