#!/bin/bash

myFunction () {
	echo "$1" #Special variable that gets the 1st parameter (argument) sent after the function call	
	echo "$2"
	echo "$3"
	return "7"  #Return value. Typically used for checking if the function executed succesfully (0) or not (nonzero). Great for comparisons.
}

myFunction "first parameter" "second parameter" "third parameter" #Parameters are seperated by a space

echo "The return value is ${$?}"

