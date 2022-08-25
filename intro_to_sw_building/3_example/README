# Example 2

## Compiling a shared library

```
 $ module purge
 $ module load gcc
```

```
 $ g++ -fPIC -c initapi.cc
 $ g++ -fPIC -c randapi.cc
 $ g++ -shared initapi.o randapi.o -o libmyrand.so
```

```
 $ ls -1
 README
 initapi.cc
 initapi.o
 libmyrand.so
 randapi.cc
 randapi.hh
 randapi.o
 test.cc
```

```
 $ g++ test.cc -L. -lmyrand -o test

 $ ./test
 ./test: error while loading shared libraries: libmyrand.so: cannot open shared object file: No such file or directory

 $ ldd test
	 linux-vdso64.so.1 (0x00007fffbb520000)
	 libmyrand.so => not found
	 libstdc++.so.6 => /lib64/libstdc++.so.6 (0x00007fffbb2d0000)
	 libm.so.6 => /lib64/power9/libm.so.6 (0x00007fffbb1a0000)
	 libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007fffbb160000)
	 libc.so.6 => /lib64/power9/libc.so.6 (0x00007fffbaf50000)
	 /lib64/ld64.so.2 (0x00007fffbb540000)
```

```
 $ echo $LD_LIBRARY_PATH
 /sw/summit/gcc/9.1.0-alpha+20190716/lib64:/opt/ibm/spectrumcomputing/lsf/10.1.0.11/linux3.10-glibc2.17-ppc64le-csm/lib

 $ export LD_LIBRARY_PATH=~/summit/handson_dev/3_example:$LD_LIBRARY_PATH

 $ echo $LD_LIBRARY_PATH
 /ccs/home/user/summit/handson_dev/3_example:/sw/summit/gcc/9.1.0-alpha+20190716/lib64:/opt/ibm/spectrumcomputing/lsf/10.1.0.11/linux3.10-glibc2.17-ppc64le-csm/lib

 $ ./test
 getRand () avg: 5
 getSRand () avg: 0.501759
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
