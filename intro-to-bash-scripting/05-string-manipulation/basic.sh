#!/bin/bash

str1="Hello, World."
echo ${str1:0:5}  #Like lists, strings can be indexed, itereated, and sliced through
echo ${str1: -6}  #They can even be indexed from the end!

str2="mSD90sfmjo"
echo ${#str2}  #Gets the length of the string

str3="I dont like bash. I dont really like bash."
echo ${str3/dont/really}  #Local replacement (replaces first instance)
echo ${str3//dont/really}  #Global replacement (replaces ALL instances)

str4="Substrings are difficult."
echo ${str4%%are*}  #Cuts off all string past (and including) substring "are"


