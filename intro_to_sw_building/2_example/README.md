# Example 2

In this example, we will be building a random number generator using multiple source files combined into a
library then linked to an executable.

## Compiling multiple source files.

In this directory there are these files:

```
 $ ls -1
 README
 initapi.cc
 randapi.cc
 randapi.hh
 test.cc
```

Similar to example one, to compile the source files into one a single executable, we could do the following:

```
 $ g++ initapi.cc randapi.cc test.cc -o test

 $ ls -1
 README
 initapi.cc
 randapi.cc
 randapi.hh
 test
 test.cc

 $ ./test
 getRand () avg: 5
 getSRand () avg: 0.501096
```

This creates our random number generator together with a small tester called `test`.
Here `g++` not only compiles our randon number generator library, but links it to together with the tester.

## Libraries

The files `initapi.cc`, `randapi.cc`, and `randapi.hh` compose our library.  Instead of one large source file, we have
divided it into three smaller pieces that make the software easier to work on as it grows.

### Header files

The file `randapi.hh` is a header file.  A header file typically contains a list of all the functions that a library provides.
This list is the list of **function declarations**.  This can be referred to as an interface.  Here we are declaring to
the compiler that a function exists and how it is called (parameters and return types).

The header is a good resource for other developers to find out how to use a library.

It is a good practice to include documentation and comments in the header file.  Also, we have named the library `randAPI`
where API refers to Application Programming Interface.  This is a common term in programming.  APIs are typically the
layer of software which is used to communicate between to two components.

In this simple example, the functionality for our library is included in the two source files, `randapi.cc` and `initapi.cc`.
The function delcarations are in the header files, while the **function definitions** are in the source files.  `randapi.cc`
provides the code for generating the random numbers while `initapi.cc` provides the necessary code to initialize our random
number generator.

### Types of libraries

The two types of libraries we will discuss are static and shared/dynamic software libraries.  A static library is a collection
of object files, conventionally ending in `.a` suffix.  When created an application using a static library, the library is
copied into the final executable file.  In our aboove compilation example, the `randapi` library is staticly link to the test
application and the result is a single executable file.

The second type of library is a shared or dynamic library.  A shared library is separate from the executable binary file and
is linked at runtime (when the application is executed).  A shared library will typically have a `.so` file extension.
Shared libraries will be covered more in the Example 3.

## Compiling a static library

```
 $ g++ -c -Wall initapi.cc
 $ g++ -c -Wall randapi.cc
 $ ar -cru libmyrand.a initapi.o randapi.o
```

This creates a library named `libmyrand.a` in three steps.  The first two commands are similar to those we used earlier,
but here we have the `-c` flag which tells g++ to only compile (not link) the source files.  Next, we issue an `ar` command
to build the library from the two compiled objects.  The `-cru` flags here are standard flags.  `c` indicated to create the
library unless it already exists, `r` replaces existing objects in the library, and `u` says to only replace if the objects
are newer than those already there.  These flags are useful when you are debugging and recompiling your code often.

Now we have `libmyrand.a` which contains both `initapi.o` and `randapi.o`.

To see the contents of a static library, you can do the following:
```
 $ ar -t libmyrand.a
 initapi.o
 randapi.o
```

## Linking to a library

We can build the tester application and connect it to our random number generator library as follows:

```
 $ g++ test.cc -L. -lmyrand -o test

 $ ./test
 getRand () avg: 5
 getSRand () avg: 0.500082
```

Here we compile `test.cc` then link the `test.o` object with `libmyrand.a` to product the `test` executable.  Here the `-L.`
is used to tell g++ that our library is in the current directory (shown as the shortcut `.`), and the `-l` flag identifies
the name of the library we wish to link against, in this case `myrand`.  g++ automatically surrounds the name of the library
with `lib` and `.a` when looking for it.

To clean up and remove files: `rm *.o test`
