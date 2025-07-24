#!/bin/bash

f_Size=0
f_Name=noise0.txt

cd noise  #Go's into "noise" directory
for file in *.txt; do  #Iterates through the files
	c_Size=$(wc -l < $file)  #Sets variable cur_Size to the value of command wc from $file
	if [[ $c_Size -gt $f_Size ]]; then #Compares for biggest one
		f_Size=$c_Size
		f_Name=$file
	fi	
done

echo "Line # | Line Length | Line Contents"
awk '{print NR, length, $0}' $f_Name | sort -k2 -nr | head -1

# Explanation of code:
#	
#	awk 'print NR, length, $0'  
#		prints every line of file noise.txt
#
#	sort -k2 -nr
#		sorts everything in reverse order (-nr) with respect to line size (-k2)
#
#	head -1
#		prints only the head (the top value, in this case the largest size)
# WARNING: This code will not work without the noise subdirectory to search through.


#This is the power of pipes! Don't be afraid to use them!!
#Bonus not included, though...

