# Example 3

## Compiling a shared library

If you are coming back to this from working on something else, a reminder to clear your environment and load the GNU compiler.

```
 $ module purge
 $ module load gcc
```

Here we will be building the same random number generator from Example 2, but in a more reusable way.  We again compile with 
the `-c` flag so that gcc will not perform the linking step, `-Wall` will make all compiler warnings into errors and halt, and 
the new flag `-fPIC` tells gcc to create Position Independent Code.  This formats the machine code in such a way that it can
be relocated within the computer's memory address space as needed.

The third line creates our shared object, `.so` file, that is analogous to the static library, `libmyrand.a` in the last example.
However, we use the `-shared` flag to enable it to be linked to other objects to form an executable.  In example 2, we created
an archive from our two source files which was then included in the final executable, here the library and executable will be
separate.

```
 $ g++ -fPIC -Wall -c initapi.cc
 $ g++ -fPIC -Wall -c randapi.cc
 $ g++ -shared initapi.o randapi.o -o libmyrand.so

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

Now we compile and link our test application to the shared library, myrand, and attempt to run it.

```
 $ g++ test.cc -L. -lmyrand -o test

 $ ./test
   ./test: error while loading shared libraries: libmyrand.so: cannot open shared object file: No such file or directory
```

The error above is because the dynamic loader does not know where to find `libmyrand.so`

To see what our executable depends on at runtime, we can use `ldd` to find the dependencies and where they are located.

```
 $ ldd test
	 linux-vdso64.so.1 (0x00007fffbb520000)
	 libmyrand.so => not found
	 libstdc++.so.6 => /lib64/libstdc++.so.6 (0x00007fffbb2d0000)
	 libm.so.6 => /lib64/power9/libm.so.6 (0x00007fffbb1a0000)
	 libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007fffbb160000)
	 libc.so.6 => /lib64/power9/libc.so.6 (0x00007fffbaf50000)
	 /lib64/ld64.so.2 (0x00007fffbb540000)
```

As you can see, our `librand.so` is listed as a dependency, but not found. This is because our working directory is not in
any of the search locations.

Dependencies are searched in the following locations and order:

Each shared library in our dependencies is searched in the following locations, in order:

  1. Directories listed in the executable's `rpath`.
  2. Directories in the `LD_LIBRARY_PATH` environment variable, which contains colon-separated list of directories (e.g., `/path/to/libdir:/another/path`)
  3. Directories listed in the executable's `runpath`.
  4. The list of directories in the file `/etc/ld.so.conf`. This file can include other files, but it is basically a list of directories - one per line.
  5. Default system libraries - usually `/lib` and `/usr/lib`.

The simplest way to add our working directory to the search path is to use the `LD_LIBRARY_PATH` environment variable.
One method would be to add the current working directory to the `LD_LIBRARY_PATH` with the `export` command.  Here we 
add the absolute (fullly specified path).

```
 $ echo $LD_LIBRARY_PATH
   /sw/summit/gcc/9.1.0-alpha+20190716/lib64:/opt/ibm/spectrumcomputing/lsf/10.1.0.11/linux3.10-glibc2.17-ppc64le-csm/lib

 $ export LD_LIBRARY_PATH=/summit/path/to/3_example:$LD_LIBRARY_PATH

 $ echo $LD_LIBRARY_PATH
   /summit/path/to/3_example:/sw/summit/gcc/9.1.0-alpha+20190716/lib64:/opt/ibm/spectrumcomputing/lsf/10.1.0.11/linux3.10-glibc2.17-ppc64le-csm/lib

 $ ./test
   getRand () avg: 5
   getSRand () avg: 0.501759
```

An alternate method of adding the directory is to prepend the variable definition to the command.  Here we use the
`.` shortcut to indicate the current working directory.

```
$ LD_LIBRARY_PATH=. ./test
  getRand () avg: 5
  getSRand () avg: 0.497713
```

It should be noted that this can cause issues if you move or copy your application or libraries to other directories.

Another method of directing the loader to where the libraries are is to use `rpath` and `runpath`.  These are variables that
are baked into the executable during linking, the difference between the two is that `rpath` is searched before `LD_LIBRARY_PATH`
and `runpath` is searched after, as indicated above.  This means that `runpath` can be dynamically changed at runtime while `rpath`
can not.

```
$ g++ test.cc -L. -lmyrand -o test -Wl,-rpath=.

$ ./test
  getRand () avg: 5
  getSRand () avg: 0.505858
```

Here the `-Wl` flag is used to pass the following, comma-separated flags to the linker.  In our case we are passing `-rpath=.`.
There are

Below you can see that `librand.so` now has a found location:

```
$ ldd ./test
        linux-vdso64.so.1 (0x00007fffb5cd0000)
        libmyrand.so => ./libmyrand.so (0x00007fffb5ca0000)
        libstdc++.so.6 => /lib64/libstdc++.so.6 (0x00007fffb5a50000)
        libm.so.6 => /lib64/power9/libm.so.6 (0x00007fffb5920000)
        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007fffb58e0000)
        libc.so.6 => /lib64/power9/libc.so.6 (0x00007fffb56d0000)
        /lib64/ld64.so.2 (0x00007fffb5cf0000)
```

To set the `runpath` variable, we have to pass `--enable-new-dtags` to the linker as well.

```
$ g++ test.cc -L. -lmyrand -o test -Wl,-rpath=.,--enable-new-dtags

$ ./test
  getRand () avg: 5
  getSRand () avg: 0.0.508202
```

### Shared Library Conventions

It should be noted that when working with shared libraries that every shared library has a "soname".  The soname has the
prefix `lib`, followed by the name of the library, the suffix `.so`, then a version number that is incremented when the
interface changes.  Each shared library also has a "real name".  This adds a period followed by a minor number to the soname
and optionally another period and release number.

As an example, shown below is the `readline` shared library on Summit.  The first entry is the undecorated library name,
`libreadline.so`.  The second is the soname, `libreadline.so.7`, and the bottom is the actual library with the full name,
`libreadline.so.7.0`.  Notice two the size of the real library is much larger than the others.  Here the soname and the
undecorated named files are simply links down to the actual library.  The linker uses the undecorated name when searching
for the appropriate library.

```
$ ll /usr/lib64/libreadline*
  lrwxrwxrwx 1 root root     16 Aug 23 11:47 /usr/lib64/libreadline.so -> libreadline.so.7
  lrwxrwxrwx 1 root root     18 Aug 23 11:47 /usr/lib64/libreadline.so.7 -> libreadline.so.7.0
  -rwxr-xr-x 1 root root 432704 Aug 12  2018 /usr/lib64/libreadline.so.7.0
```

### References

https://amir.rachum.com/blog/2016/09/17/shared-libraries/
https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html
https://cseweb.ucsd.edu/~gbournou/CSE131/the_inside_story_on_shared_libraries_and_dynamic_loading.pdf
https://stackoverflow.com/questions/5311515/gcc-fpic-option
https://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html
https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

