# Example 4

## Makefiles

In this directory there are these files:

```
makefile1
makefile2
makefile2
README
initapi.cc
randapi.cc
randapi.hh
test.cc
```

Up until now we have been compiling our libraries and applications with commands on the command line, like this:
```
 $ g++ initapi.cc randapi.cc test.cc -o test
```
This does the job, but it might be somewhat hard to remember, and in the typical test/modfiy/debug cycle having to use the
up arrow to find the right compile command everytime can be tedious.  Adding more and more files to this compicates it even
further. Also, this method recompiles every file each time you execute it which can be time-comsuming.

One solution to this is to use a makefile.

---
**NOTE**

In order to use each makefile, rename the one you are working with to `makefile`.  When you are done, change the name back
to `makefileX` so that `make` does not recognize it.
---

### Simple makefile

The very simplest makefile you can write is might look like this:
```
  ## makefile1

  simple_test: initapi.cc randapi.cc test.cc
  	g++ -o test initapi.cc randapi.cc test.cc -I.    ## Important note that this line starts with a TAB, not spaces.
```

A makefile is essentially a set of rules.  In general, a rule looks like the following:
```
  target: prerequisites/dependencies
    command
    command
    command
```

- Targets can be filenames, separated by spaces, but typically there is only one per rule.
- Commands are a series of steps used to make the target.  These NEED to start with a tab, not spaces.
- Prerequisistes, or dependencies, are file names separated by spaces.  These files need to exist before
  the commands for the target are run.

Putting this into a file named `makefile` or `Makefile` then typing `make` will execute the compile command just as if it
were typed onto the command line.  `make` will execute the first rule in the file, in our case that is `simple_test`.
That rule states that the 

### Using variables and macros

In the next make file, we define the constants `CXX` and `CXXFLAGS`, these are special constants that tell `make` how to
compile our source files.  `CXX` defines the compiler and `CXXFLAGS` are the flags passed to the compiler.

Another change is using `.o` files on the dependency list (on the line: `simple_test: initapi.o ...`).  This tells `make`
that to build those sourcefiles first before buiding the executable `test`.

```
# Using variables and macros

CXX=g++        # Defines our compiler
CXXFLAGS=-I.   # Flags to pass to compiler command

simple_test: initapi.o randapi.o test.o
	$(CXX) -o test initapi.o randapi.o test.o
```

This file is likely sufficient for most small projects, but lacks dependency on the include files, `.hh` files.  If you
make a change to `randapi.hh`, then make will not recognize that it needs to rebuild the library.  The next example adds
this and a few other features.

### A more complete example

```
# Tracking header files too

CXX=g++
CXXFLAGS=-I.
DEPS = randapi.hh   # Macro for set of header files on which the source files depend

%.o: %.cc $(DEPS)   # This rule says that all .o files depend on the .cc version of the file and the headers in DEPS
  $(CXX) -c -o $@ $< $(CXXFLAGS)

  # -o $@ names the object file with what is on the left side of the :, in this case it will be a file.o
  # $< is the first item on the dependencies list, in this case the .cc file
  # Equivalent to: g++ -c -o myfile.o myfile.cc -I. --- for each myfile.o listed on line 27

simple_test: initapi.o randapi.o test.o
  $(CXX) -o test initapi.o randapi.o test.o

.PHONY: clean

clean:
  rm -f *.o *.so test test1
```

References
[A simple makefile tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
