# Example 2

## Compiling multiple source files.

In this directory there are these files:

```
README
initapi.cc
randapi.cc
randapi.hh
test.cc
```

To compile the source files into one a single executable, we could do the following:
```
 $ g++ initapi.cc randapi.cc test.cc -o test
```
This creates our random number generator together with a small tester called `test`.
Here `g++` not only compiles our randon number generator library, but links it to together with the tester.

## Compiling a static library

```
 $ g++ -c -Wall initapi.cc
 $ g++ -c -Wall randapi.cc
 $ ar -cru libmyrand.a initapi.o randapi.o
```

This creates a library named `libmyrand.a` in three steps.  The first two commands are similar to those we used earlier,
but here we have the `-c` flag which tells gcc to only compile (not link) the source files.  Next, we issue an `ar` command
to build the library from the two compiled objects.  The `-cru` flags here are standard flags.  `c` indicated to create the
library unless it already exists, `r` replaces existing objects in the library, and `u` says to only replace if the objects
are newer than those already there.

Now we have `libmyrand.a` which contains both `initapi.o` and `randapi.o`.

To see the contents of a static library, you can do the following:
```
 $ ar -t libmyrand.a
 initapi.o
 randapi.o
```

## Linking to a library

We can build the tester application as follows:

```
 $ g++ test.cc -L. -lmyrand -o test

 $ ./test
 getRand () avg: 5
 getSRand () avg: 0.500082
```

Here we compile `test.cc` then link the `test.o` object with `libmyrand.a` to product the `test` executable.  Here the `-L.`
is used to tell gcc that our library is in the current directory (shown as the shortcut `.`), and the `-l` flag identifies
the name of the library we wish to link against, in this case `myrand`.  gcc automatical surrounds the name of the library
with `lib` and `.a` when looking for it.

To clean up and remove files: `rm *.o test`
