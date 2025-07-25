#!/bin/bash

read inp1  #Basic form of reading input
read -p "Enter input: " inp2  #You can send the -p flag to print a "prompt" to screen for input

echo "Your first input is (${inp1})!" 
echo "Your second input is (${inp2})!"

read -p "Enter 3 items seperated by a space: " l0 l1 l2  #You can have multiple inputs on one line
echo "Your array is ((${l0} ${l1} ${l2}))"

