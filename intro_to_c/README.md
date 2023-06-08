# Introduction to C Programming

C is a general-purpose programming language initially developed by Dennis Ritchie at Bell Laboratories. 

As C is a Compiled Language, a compiler is a program that converts high-level code (like C) into machine code that runs on the system. 
Before a program is executed, the compiler compiles the program and turns it into a binary executable, whereas in an interpreted language like Python, there is an interpreter that converts from human-readable into machine-readable code as you go through the program without the need for a separate compilation step.

Many operating systems, as well as Perl, PHP, Python, and Ruby, are written in C.
C is one of the common programming languages used in HPC.

Table of Contents:
* [Basics of C](#simple)

 * [Data Types](#dt)
	* [Basic Data Types](#bdt)
	* [`printf` function](#pf)
	* [Arrays](#arrays)
* [Loops](#loops)
	* [While Loop](#while)
	* [`do-while` Loop](#dowhile)
	* [`for` Loop](#for)
* [If Statements](#if)
 	* [Arithmetic Operators](#aop)
 	* [Relational Operators](#rop)
 	* [Assignment Operators](#asop)
 	* [Logical Operators](#lop)
* [Functions](#functions)
  	* [Standard Library Functions](#slf)
 	* [User-Defined Functions](#udf)
* [Addresses and Pointers](#add)
* [Memory Allocation](#mem)
  	* [Stack](#stack)
  	* [Heap](#heap)
* [Exercises](#exercises)

Before getting started, make sure that you have a fresh Unix terminal open. Once you have a terminal open, change directories to the intro_to_c directory:
```
$ cd ~/foundational_hpc_skills/intro_to_c
```
> Note: The above syntax is assuming you stored the `foundational_hpc_skills` repository in your Home directory.

### <a name="simple"></a>1. Simple Example
```
/*------------------------------------------------------------
Program that prints the value of an integer to the screen.
------------------------------------------------------------*/
#include <stdio.h>

int main(){
    int a = 3;
    printf("The value of this integer is %d\n", a);
    return 0;
}

```

The `#include <stdio.h>` statement is a C preprocessor directive telling the compiler to include contents of the header file in angle brackets.

The `int main()` is a declaration of a function called main, which is where the execution of the program begins.  `main` is included in all C programs. The “int” indicates that the function will return an integer value.

`{` and `}` are curly braces that indicate the beginning and end of the main function.

`int a = 3` defines an integer called “a” and assigns it a value of 3.

`;` is a semicolon used to indicate the end of each statement.

`printf` is a function that sends formatted output to stdout (typically the terminal from which the program was run). Stdout refers to standard output, and when the user runs the program, it prints the output data to the display screen. `printf` is defined in the stdio.h header file, which includes the standard input/output functions. 

`return 0` is a return value “returned” to the run-time environment. Typically, a value of 0 indicates a normal/successful exit.

To compile the C program, use the gcc compiler to compile the C code into an executable:
```
$ gcc simple.c
```
> Note: $ is known as the Bash Prompt, which means you can enter a command and press Enter to execute it.

An executable is named a.out by default. To view the list of files in a current directory, use the `ls` command: 
```
$ ls
a.out  simple.c
```

To run the program, use the following:
```
#./a.out
The value of this integer is 3
```
Specifying `./` before the command or program name indicates that the program should be found and executed in the current directory.

<ins>To specify Output File Name </ins>:
To compile the C program, use the gcc compiler to compile the C code into an executable:
```
$ gcc -o simple simple.c
```
-o is compiler flag that allows you to name the executable

To view the list of files in the directory:
```
$ ls
simple  simple.c
```
Run the program:
```
#./simple
The value of this integer is 3
```

### <a name="dt"></a>2. Data Types
Variables are named storage areas

For example, `int a = 5` creates a variable (storage area in memory) named “a” and saves the value of 5 in that memory location.

Variables of different data types occupy different amounts of memory and can store different ranges of values, and these variables must be declared before use.

### <a name="bdt"></a> Basic Data Types

| Name          | Type          | Range of Values | Size (B) |
| ------------- | ------------- | -------------   | -------------   |           
| Char          | Character     | ASCII Characters| 1  |
| Int		 | Integer   | -2,147,483,648 to 2,147,483,647   | 4 |
| Float  | Decimal (precision to 6 places)   | 1.2e-38 to 3.4e38   | 4 |
| Decimal  | Decimal (precision to 15 places)   | 2.3e-308 to 1.7e308   | 8 |

### <a name="pf"></a> Printf Function
#### Formatted Output with `printf` function
<ins>Example 1</ins>:

Code:
```
printf("Hello World");
```
Output:
```
 $ ./a.out
Hello World$
 ```
Result: Hello World
> Note: To get a new line on the prompt, insert a new line using (\n)

<ins>Example 2</ins>:

Code:
```
printf("Hello World\n");
```
Output:
```
 $ ./a.out
Hello World
$
 ```
Result: Hello World (with a new line)

### Format Tags: represented by a percent sign (%) followed by a character that specifies the type of formatting
* %c: Character
* %d: Integer
* %f: Floating-point number
* %s: String

 <ins>Example 3</ins>: 
```
int i = 2;
printf(“The value of the integer is %d\n”, i);
```
* i represents the variable whose value is used in the format tag

Result: The value of the integer is 2
 
 <ins>Example 4</ins>:
 ```
float x = 3.14159;
printf(“The value of the float is %.2f\n”, x);
```
* x represents the variable whose value is used in the format tag

Result: The value of the float is 3.14
 
### <a name="arrays"></a> Arrays
### C Arrays - Data structure that holds a fixed number of data elements of a specific type

```
int A[10]; // declares an array of 10 integers
```
| A[0]          | A[1]          | A[2] | A[3] | A[4]         | A[5]        | A[6] | A[7]|  A[8] | A[9]|
| ------------- | ------------- | -------------   | -------------   | ------------- | -------------   | -------------   | ------------- | -------------   | -------------  |       

> Note: // is used to comment the code 
* Each Element is 4 bytes for an integer

To assign values to the array elements,
```
A[0] = 7;
A[1] = 32;
A[2] = 256;
A[3] = 17;
A[4] = -20;
A[5] = 22;
A[6] = 1;
A[7] = 0;
A[8] = 59;
A[9] = -2;
```

```
printf(“The value of A[3] = %d\n”, A[3]);
```
Output:
The value of A[3] = 17

Example that shows the use of variables, arrays, and the printf() function, as well as how to find the size of data types using the sizeof() function:
```
/*------------------------------------------------------------
Program that prints that value of several variables to the
screen along with their size in bytes (in a table format).
------------------------------------------------------------*/

#include <stdio.h>

int main(){
	
    char a      = 'X';
    int i       = 22;
    float x     = 3.14159265358979323846264338327;
    double y    = 3.14159265358979323846264338327;
    char pi[31] = "3.14159265358979323846264338327";

    printf("\n--------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20s %-20s \n", "Variable", "Data Type", "Value", "Size (B)");
    printf("--------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20c %-20lu \n", "a", "char", a, sizeof(char));
    printf("%-20s %-20s %-20i %-20lu \n", "i", "int", i, sizeof(int));
    printf("%-20s %-20s %-20.16f %-20lu \n", "x", "float", x, sizeof(float));
    printf("%-20s %-20s %-20.16f %-20lu \n", "y", "double", y, sizeof(double));
    printf("--------------------------------------------------------------------------\n");
    printf("Actual value of pi ( 29 decimal places ): 3.14159265358979323846264338327\n\n");

    return 0;
}
```

Output:
```
--------------------------------------------------------------------------
Variable             Data Type            Value                Size (B)             
--------------------------------------------------------------------------
a                    char                 X                    1                    
i                    int                  22                   4                    
x                    float                3.1415927410125732   4                    
y                    double               3.1415926535897931   8                    
--------------------------------------------------------------------------
Actual value of pi ( 29 decimal places ): 3.14159265358979323846264338327
```


### <a name="loops"></a>3. Loops

### <a name="while"></a>a. While Loops

```
while(expression){
// Execute loop statements until expression evaluates to 0
}
```
* The expression is evaluated before each iteration

Example of while loop (03_loops/while_loop/while_loop.c):
```
#include <stdio.h>

int main(){

    float x = 1000.0;

    while(x > 1.0){
        printf("x = %f\n", x);
        x = x / 2.0;
    }

    return 0;
}
```

To compile and run the code:
```
$ gcc -o while_loop while_loop.c

$ ./while_loop
x = 1000.000000
x = 500.000000
x = 250.000000
x = 125.000000
x = 62.500000
x = 31.250000
x = 15.625000
x = 7.812500
x = 3.906250
x = 1.953125
```

### <a name="dowhile"></a> b. Do While Loops

```
do {
// Execute loop statements until expression evaluates to 0
} while (expression)
```
* The expression is evaluated after each iteration

Example of while loop (03_loops/while_loop/do_while_loop.c):
```
#include <stdio.h>

int main(){

    int j = 10; // Declare integer j and set its value to 10

    /* --------------------------------------
    do while loop
        -> Executes statements at least 1 time, 
           even if condition is not met 
    -------------------------------------- */
    do {
        printf("do-while: j = %d\n", j);
        j = j + 1;
    } while(j > 10 && j < 20);

    return 0;
}
```
To compile and run code:
```
$ gcc -o do_while_loop do_while_loop.c

$ ./do_while_loop
```
Output:
```
do-while: j = 10
do-while: j = 11
do-while: j = 12
do-while: j = 13
do-while: j = 14
do-while: j = 15
do-while: j = 16
do-while: j = 17
do-while: j = 18
do-while: j = 19
```
### <a name="for"></a>c. For Loops

```
for(initialization; conditional_expression; iteration){ 
// loop statements
}
```
* conditional_expression: Evaluated before body of loop
* iteration: Evaluated after body of loop

Example of for loop (03_loops/for_loop/for_loop.c):
```
/*------------------------------------------------------------
Program showing the basic idea of a for loop. For each
iteration of the loop, it prints the iteration number (i) 
along with the sum of all values of i up until that point.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int N   = 10;
    int sum = 0;

    for(int i=0; i<N; i++){

        sum = sum + i;
        printf("Iteration: %d, sum = %d\n", i, sum);

    }

    return 0;
}
```

To compile and run code:
```
$ gcc -o for_loop for_loop.c

$ ./for_loop
Iteration: 0, sum = 0
Iteration: 1, sum = 1
Iteration: 2, sum = 3
Iteration: 3, sum = 6
Iteration: 4, sum = 10
Iteration: 5, sum = 15
Iteration: 6, sum = 21
Iteration: 7, sum = 28
Iteration: 8, sum = 36
Iteration: 9, sum = 45
```
<ins>Continue Statement</ins>:
When a continue statement is encountered within a loop, the remaining statements in the loop body (after the continue) are skipped and the next iteration of the loop begins.

Example of continue statement(03_loops/continue/continue.c):
```
/*------------------------------------------------------------
Program showing a continue statement within a for loop. The 
loop iteration number is printed except for the value 7 since
the continue statement moves on to the next iteration of the 
loop.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    for(int i=0; i<10; i++){

        if(i == 7){
            continue;
        }

        printf("Loop iteration: %d\n", i);
    }	

    return 0;
}
```
To compile and run code:
```
$ gcc –o continue continue.c
$ ./continue
Loop iteration: 0
Loop iteration: 1
Loop iteration: 2
Loop iteration: 3
Loop iteration: 4
Loop iteration: 5
Loop iteration: 6
Loop iteration: 8
Loop iteration: 9
```
<ins>Break Statement</ins>:
When a break statement is encountered within a loop, the loop is terminated.

Example of break statement(03_loops/break/break.c):
```
/*------------------------------------------------------------
Program showing a continue statement within a for loop. The 
loop iteration number is printed except for the value 7 since
the continue statement moves on to the next iteration of the 
loop.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    for(int i=0; i<10; i++){
        if(i == 7){
            continue;
        }
        printf("Loop iteration: %d\n", i);
    }	

    return 0;
}
```
To compile and run code:
```
$ gcc –o break break.c
$ ./break
Loop iteration: 0
Loop iteration: 1
Loop iteration: 2
Loop iteration: 3
Loop iteration: 4
Loop iteration: 5
Loop iteration: 6
```

### <a name="if"></a>4. If Statements
```
int A = 10;
int B = 2;
```

### <a name="aop"></a>a. Arithmetic Operators
| Operator          | Syntax        | Output |
| ------------- | ------------- | -------------   |          
| + Add          | A + B     | 12| 
| - Subtract          | A - B     | 8| 
| * Multiply          | A * B     | 20|
| / Divide          | A / B     | 5| 
| % Modulus (Remainder after division of B into A) | A % B     | 0 | 
| A++ Increment (same as A = A + 1) | A++     | 11| 
| B-- Decrement (same as B = B - 1) | B--    | 1| 


### <a name="rop"></a>b. Relational Operators
Relational Operators tests relationship between two operands
* If true, returns 1
* If false, returns 0

| Operator          | Syntax        | Output | True/False |
| ------------- | ------------- | -------------   | -------------   |     
| == Equal to          | A == B;     | 0 | False |
| != Not equal to          | A != B;     | 1 | True |
| > Greater than          | A > B;     | 1 | True |
| < Less than          | A < B;     | 0 | False |
| >= Greater than or equal to          | A >= B;     | 1 | True |
| <= Less than or equal to          | A >= B;     | 0 | False |

### <a name="asop"></a>c. Assignment Operators
| Operator         | Syntax        | Equivalent Expression | Assigned Value to A|
| ------------- | -------------   | -------------   |     -------------   |  
| =     | A = B; | A = B | 2 |
| +=     | A += B; | A = A + B; | 12 |
| -=     | A -= B; | A = A - B; | 8 |
| *=     | A *= B; | A = A * B; | 20 |
| /=     | A /= B; | A = A / B; | 5 |
| %=     | A %= B; | A = A % B; | 0 |

### <a name="lop"></a>d. Logical Operators
```
int A = 10;
int B = 2;
int C = 5;
```
| Operator         | Meaning        | Syntax | Output | True/False |
| ------------- | -------------   | -------------   |     -------------   |      -------------   |
| && And     | True if both true | ((A > B) && (B == C)); | 0 | False |
|  &#124; &#124; Or  | True if at least 1 is true | ((A > B)  &#124; &#124; (B == C)); | 1 | True |
| ! Not     | Returns the opposite | !(B == C); | 1 | True |


<ins>Syntax of If Statement</ins>:

```
if(condition_1){
// Execute these statements if condition_1 is met
 }
 else if(condition_2){
// Execute these statements if condition_2 is met
} else{
// Execute these statements if other conditions are not met
}
```
Once a condition is met, the statements associated with that section are executed and all other sections are ignored.

Example:
```
/*------------------------------------------------------------
Program showing the use of an if-elseif-else statement.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int i = 1;

    if(i < 1){
        printf("i = %d (i < 1)\n", i);
    }
    else if(i == 1){
        printf("i is equal to 1\n");
    }
    else{
        printf("i = %d (i > 1)\n", i);
    }

    return 0;
}
```
To compile and run code:
```
$ gcc –o if_statement if_statement.c
$ ./if_statement
i is equal to 1
```

### <a name="functions"></a>5. Functions
A reusable block of code that performs a specific task

### <a name="slf"></a> a. Standard Library Functions
C built-in functions that can be accessed with appropriate #include statements

* We have already encountered the printf function, which can be used by including the stdio.h header file
* There are many other C standard library functions defined in other header files (math.h, stdlib.h, string.h, etc).

* These functions should be used whenever possible in order to save time (why re- invent the wheel) and because they are well-tested and portable.
 

### <a name="udf"></a> b. User-Defined Functions
Syntax:
```
return_type function_name(type1 arg1, type2 arg2, ...) { 
// Function Body
}
```

Example:
```
/*-------------------------------------------------
Program that shows how to use user-defined
functions. The function simply adds two integers.
-------------------------------------------------*/
#include <stdio.h>

// Function Definition
int add_numbers(int i, int j){

    int result;
    result = i + j;

    return result;
}

// Main Function
int main(){

    int num1 = 3;
    int num2 = 7;

    int sum = add_numbers(num1, num2);
    printf("The sum of num1 and num2 is %d\n", sum);

    return 0;
}
```
* Formal parameters/arguments: (int i, int j)
* Actual parameters/arguments: (num1, num2)

To compile and run code:
```
$ gcc –o add_two_numbers add_two_numbers.c
$ ./add_two_numbers
The sum of num1 and num2 is 10
```

Example of function (05_functions/change_value/change_value.c):
```
/*---------------------------------------------------------------
Program that INCORRECTLY shows how to use a function to change
the value of an integer. This is meant to show that C functions
are "call by value" by default.
---------------------------------------------------------------*/

#include <stdio.h>

// Function Definition
void change_number(int i){
    i = 2;
    printf("Inside the function, the number's value is %d\n", i);
}

// Main Function
int main(){

    int number = 1;
    printf("\nBefore calling the function, number = %d\n", number);

    change_number(number);

    printf("After calling the function, number = %d\n\n", number);

    return 0;
}
```
To compile and run code:
```
$ gcc –o change_value change_value.c
$ ./change_value
Before calling the function, number = 1
Inside the function, the number's value is 2
After calling the function, number = 1
```
<ins>Call By Value</ins>:
* The values of the actual arguments are copied to the formal arguments.
* Changes to the formal arguments do not affect the actual arguments.

### <a name="add"></a>6. Addresses and Pointers
Addresses and pointers allow programmers to effectively utilize memory and manipulate data.

<ins>Variable Addresses</ins>:
* The memory address of a variable can be referenced using the reference operator, &

```
 #include <stdio.h>
 int main(){
   int i = 1;
   printf("The value of i:   %d\n", i);
   printf("The address of i: %p\n", &i);
   return 0;
 
 }
```
```%p```: format tag to print address
```&```:  reference operator – gives the address of the variable

```
$ gcc –o variable_addresses variable_addresses.c
$ ./variable_addresses
The value of i: 1
The address of i: 0x7fff3e720c2c (this address will vary)
```
<ins>Pointer Variables</ins>:
Pointers: special variables in C to store memory addresses
`*`: used to declare pointer

Example of using Addresses and Pointers (06_addresses_and_pointers/pointers_1/pointers_1.c)
```
#include <stdio.h>

int main(){
    float x = 2.713;
    float *p_x;

    p_x = &x;

    printf("The value of x:   %f\n", x);
    printf("The address of x: %p\n", &x);
    printf("The value of p_x: %p\n", p_x);
    printf("The value stored at the memory address stored in p_x: %f\n", *p_x);

    return 0;
}
```

``` float *p_x; ```: The pointer is assigned the value of the memory address of x
``` p_x = &x; ```: The pointer is assigned the value of the memory address of x
``` *p_x```: * (dereference operator) – gives the value stored at a memory address

To compile and run code:
```
$ gcc -o pointers_1 pointers_1.c

$ ./pointers_1
The value of x: 2.713000
The address of x: 0x7fff5ce8aa68
The value of p_x: 0x7fff5ce8aa68
The value stored at the memory address held in p_x: 2.713000
```

Another Example of using Addresses and Pointers (06_addresses_and_pointers/pointers_2/pointers_2.c)
```*p_x = 3.141```: (dereference operator) – also allows you to change the value stored at that memory address

<ins>Back to Functions</ins>:
```
/*---------------------------------------------------------------
Program that CORRECTLY shows how to use a function to change
the value of an integer. This is meant to show how to "call a
function by reference".
---------------------------------------------------------------*/

#include <stdio.h>

// Function Definition
void change_number(int *i){
    *i = 2;
    printf("Inside the function, the number's value is %d\n", *i);
}

// Main Function
int main(){

    int number = 1;
    printf("\nBefore calling the function, number = %d\n", number);

    change_number(&number);

    printf("After calling the function, number = %d\n\n", number);

    return 0;
}
```
To compile and run code:
```
$ gcc –o change_value_correct change_value_correct.c
$ ./change_value_correct
Before calling the function, number = 1
Inside the function, the number's value is 2
After calling the function, number = 2
```
Remember, the * used declare the pointer variable, i, in the function argument is different than the * used within the body of the function. To be clear,
```int *i```: The * here is simply because this is how you declare a pointer to an integer.

<ins>Call by Reference</ins>:
```*i = 2```
```printf(“ ... %d\n”, *i)```:  

The * in these statements is the dereference operator, which allows you to access the value of the variable associated with the memory address.

### <a name="mem"></a>7. Memory Allocation
### <a name="stack"></a> Stack

* Region of computer memory that stores temporary variables
* When a new function is called the variables are created on stack
* When the function returns, the memory is returned to the stack (LIFO)
* Memory managed for you
* Variables can only be accessed locally
* Variable size must be known at compile time

### <a name="heap"></a> Heap

* Region of compute memory for dynamic allocation
* No pattern to allocation/deallocation (user can do this any time) – Memory managed by user
* E.g. using malloc(), free(), etc.
* Variables can be accessed globally
* Variable size can be determined at run time

<ins>Static</ins>:
Example of Static Memory Allocation (07_memory_allocation/static.c):
```
/*------------------------------------------------------------
Program showing usage of a statically-allocated array.
------------------------------------------------------------*/

#include <stdio.h>

int main(){

    // Statically-allocated array of floats
    int N = 5;
    float f_array[N];

    for(int i=0; i<N; i++){
        f_array[i] = 0.25*i;
    }

    for(int i=0; i<N; i++){
        printf("f_array[%d] = %f\n", i, f_array[i]);
    }

    return 0;
}
```
To compile and run code:
```
$ gcc -o static static.c
$ ./static
f_array[0] = 0.000000
f_array[1] = 0.250000
f_array[2] = 0.500000
f_array[3] = 0.750000
f_array[4] = 1.000000
```

<ins>Dynamic vs Static Memory Allocation</ins>:
| Differences         | Dynamic Memory        | Static Memory | 
| ------------- | -------------   | -------------   |
| Allocation Occurs At          | Runtime       | Compile Time | 
| Uses          | Heap       | Stack | 
| Reusability          | Reusable memory       | No memory reusability | 

<ins>Dynamic</ins>:
Example of Dynamic Memory Allocation (07_memory_allocation/dynamic.c):
```
/*------------------------------------------------------------
Program showing usage of a dynamically-allocated array.
------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    // Dynamically-allocated array of floats
    int N = 5;
    float *f_array_dyn = malloc(N*sizeof(float));

    for(int i=0; i<N; i++){
        f_array_dyn[i] = 0.25*i;
    }

    for(int i=0; i<N; i++){
        printf("f_array_dyn[%d] = %f\n", i, f_array_dyn[i]);
    }

    free(f_array_dyn);

    return 0;
}
```
``` malloc(N*sizeof(float))```: Allocates N*sizeof(float) bytes of memory and returns pointer to the block of memory

```free(f_array_dyn)```: Releases block of memory associated with f_array_dyn

To compile and run code:
```
$ gcc –o dynamic dynamic.c
$ ./dynamic
f_array_dyn[0] = 0.000000
f_array_dyn[1] = 0.250000
f_array_dyn[2] = 0.500000
f_array_dyn[3] = 0.750000
f_array_dyn[4] = 1.000000
```

### <a name="exercises"></a>8. Exercises and Resources
<ins>Exercises that go with these slides (as well as some examples to work through)</ins>:
* https://github.com/olcf/foundational_hpc_skills 

<ins>Other sites</ins>:
* https://en.cppreference.com/w/c/language
* https://en.wikibooks.org/wiki/C_Programming
* https://stackoverflow.com/questions/tagged/c

* Many other tutorials can be found by googling “c programming language”

* Website with many practice problems – https://projecteuler.net/
