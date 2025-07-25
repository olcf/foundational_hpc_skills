#!/bin/bash

a=14
b=2
c="abc"

echo a + b   #a and b are not refrenced
echo $a + $b   #a and b are refrenced, but not added
echo "$((a + b))"  #a and b are refrenced, encapuslated in arithmetic, and computed
echo "$((a * b))"
echo "$(((a - b) / 2))"  #The rules of PEDMAS still apply. This is how you handle paranthesis.

echo $c
echo "$((c+3))"  #Attempts to treat c as an integer. Since is is a string, the integer value it assigns is 0.



