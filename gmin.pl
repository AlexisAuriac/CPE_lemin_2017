#!/usr/bin/perl -w

use strict;

if (scalar @ARGV < 3) {
    print << 'END_USAGE';
usage : ./gmin.pl size density nb_of_ants
DESCRIPTION
    size         number of rooms
    density      percentage of probability of connexions between rooms
    nb_of_ants   number of ants 
END_USAGE
    exit -1;
}

my ($size, $density, $ants) = @ARGV;

my $home = int(rand($size));
my $end;

do {
    $end = int(rand($size))
} until ($end != $home);

print $ants . "\n";
for (my $i = 0 ; $i < $size ; ++$i) {
    print "##start\n" if ($i == $home);
    print "##end\n" if ($i == $end);
    print $i;
    print " " . int(rand(10 * $size));
    print " " . int(rand(10 * $size));
    print "\n";
}

for (my $i = 0 ; $i < $size ; ++$i) {
    for (my $j = 0 ; $j < $size ; ++$j) {
	if ($density > int(rand(100))) {
	    print $i . "-" . $j . "\n";
	}
    }
}
