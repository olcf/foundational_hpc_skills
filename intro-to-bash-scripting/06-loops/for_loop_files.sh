#!/bin/bash

for file in file*; do  #file* finds all files with name 'fileX' followed by whatever characters 'X' and onward.  
	echo "${file} contents:"
	cat $file
	echo ""
done
