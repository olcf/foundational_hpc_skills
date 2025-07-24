#!/bin/bash

grep "Line" < file.txt  #Takes input from file.txt and greps for "Line".

line=$( wc < file.txt )  #You can set directed input as a variable like so. 
#In this case, we are sending file.txt into command wc, which counts the size of the file.

echo $line  #This will be explained later

