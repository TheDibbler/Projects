#!/usr/bin/perl -w

#
# Arduino -> Perl -> MySQL DB
#

use strict;
use warnings;

use Device::SerialPort::Arduino;
use JSON;


my $Arduino = Device::SerialPort::Arduino->new(
	port => '/dev/ttyACM0',
	baudrate => 9600,
	databits => 8,
	parity => 'none',
	
);


while(1) {

	# Inform Arduino we're ready for data.
	$Arduino->communicate('Z');

	my $dataSerial = $Arduino->receive();

	my @dataStream = split(/\n/, $dataSerial);

	foreach (@dataStream) {
		
		my $query = "INSERT INTO rec_lab ( sensorName, airTemp, airHumidity, airPressure ), VALUES$_";
		print $query, "\n";
		sleep(5);
	}

		
}


exit();
