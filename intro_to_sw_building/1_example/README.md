# Example 1

## Introduction

This tutorial is designed to get you started with the fundamentals of building software.
We will be using C++ as our programming language of choice, but the principles are the
same for C.

### Environment setup

First on the OLCF machines various software tools and environments are controlled by 
loading and unloading modules, what they actually do will be explained as we go along.
To rid our environment of tools we do not need, execute the following:

```
 $ module purge
```

This will remove the packages loaded by default.  To load the recommended compiler, we do:

```
 $ module load gcc
```

This brings the default GNU compiler into the environment so we can use it to compile
our examples.  To see the loaded modules, you can run:

```
 $ module list

 Currently Loaded Modules:
   1) gcc/9.1.0

```

To verify that this is working, you can check the version by running:

```
 $ g++ --version
 g++ (GCC) 9.1.0
 Copyright (C) 2019 Free Software Foundation, Inc.
 This is free software; see the source for copying conditions.  There is NO
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Now we are ready to build software with GCC.

### First steps

In this directory there are the following files:

```
 $ ls -1
 README.md
 hello.cc
```

As with all good programming tutorials this starts with `Hello, world!`
In the C++ source file, `hello.cc`, we have:

```
#include <iostream>

int main () {
  std::cout << "Hello, world!\n";
}
```

We compile and execute the example by running the commands:

```
 $ g++ hello.cc

 $ ./a.out
 Hello, world!
```

Congratulations.  You've built the first example application and executed it.  Calling `g++` on `hello.cc`
compiles and links together everything that is needed to run the application.  In this case, it creates a 
file called `a.out` in the same directory that we are in.  `a.out` is the default name of a file created by
`g++`.  If you add the `-o <name>` flag then you can specify the name of the executable file as show here:

```
 $ g++ -o hello hello.cc

 $ ls -1
 README.md
 a.out
 hello
 hello.cc

 $ ./hello
 Hello, world!
```

Now you have an executable called `hello` that will output "Hello, world!" to the screen.

### Compilation Details

Note that the single command compiles AND links the application.  The first step, compiling, takes the 
human-readable (we hope) code and translates it to something that a computer can read called machine 
language.  The output from compilation is an object file.  In the second step, these objects files are then 
combined with any outside files, or libraries, to create an executable file.  In the next examples in this
tutorial, we will break this down so you can see the individual steps.

If you look at our `hello.cc`, on the first line there is:
```
#include <iostream>
```
`iostream` is the name of a library used to display output to the screen, read input from keyboard, and 
various other input/output related functions.  We enclose it in `<>` because it is what is known as a standard 
library and is located somewhere on the computer you are using.  `g++` knows where it is and can use it without 
any additional effort by us.  We will discuss more about libraries in the next example.

The keyword `#include` is a special indicator to `g++` that `iostream` is needed to be included in our hello 
world executable.

