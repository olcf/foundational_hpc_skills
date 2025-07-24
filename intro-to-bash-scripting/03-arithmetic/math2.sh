#!/bin/bash

a=10
b=3
c=2.3

echo "scale=2; $a / $b" | bc  #MUST use the referal of variables with $ to refer to their values here. Notice the | pipe operator.
#3.33
echo "scale=3; $a / $b" | bc  #More accuracy than previous
#3.333
echo "scale=1; $a + $c" | bc  #Will read $c as a float
#12.3

echo "scale=4; s(1.571)" | bc -l  #Sine of ~(pi / 2)
#1.0000
echo "scale=4; l(e(2))" | bc -l  #Natural log of e^2
#1.9999


echo "scale=3; ($a / $b) + $c" | bc  #Example of compound equation with floats
#5.633

