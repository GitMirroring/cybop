###############################################################################
# CYBOI UTIL                                                                  #
# Code::Blocks Project File Updater                                           #
#-----------------------------------------------------------------------------#
# Authors: Kevin Klein, Tobias Donix                                          #
###############################################################################

#!/usr/local/bin/perl

use File::Find::Rule;
use Cwd;
use XML::LibXML;

#Project File Handle
my $pfPath = 'ide/codeblocks/CYBOI.cbp';
open my $in, '<', $pfPath;
binmode $in; # drop all PerlIO layers possibly created by a use open pragma
$xmlDoc = XML::LibXML->load_xml(IO => $in);
close $in;

my $projectNode  = $xmlDoc->findnodes("//Project")->[0];

#Drop all unit nodes
my @unitNodes = $xmlDoc->findnodes("//Unit");
foreach my $unitNode (@unitNodes) {
	$unitNode->unbindNode;
}

#Read out files
#And write nodes
my @cFiles = File::Find::Rule->file()
                            ->name( '*.c' )
                            ->in( getcwd . '/src' );
							
my @hFiles = File::Find::Rule->file()
                            ->name( '*.h' )
                            ->in( getcwd . '/src' );
for my $file (@cFiles) {
	my @pieces = split(/src/, $file);
	my $correctPath = "../../src" . $pieces[1];
	
	my $node = XML::LibXML::Element->new("Unit");
	$node->setAttribute('filename', $correctPath);

	my $optionNode = XML::LibXML::Element->new("Option");
	$optionNode->setAttribute('compilerVar', 'CC');
	
	$node->addChild($optionNode);
	
	$projectNode->addChild($node);
}

for my $file (@hFiles) {
	my @pieces = split(/src/, $file);
	my $correctPath = "../../src" . $pieces[1];
	
	my $node = XML::LibXML::Element->new("Unit");
	$node->setAttribute('filename', $correctPath);
	
	$projectNode->addChild($node);
}

#Save document
open my $out, '>', $pfPath;
binmode $out;
$xmlDoc->toFH($out);
close $out;