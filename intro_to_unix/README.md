# Working in a Unix System: Basic Commands for Basic Tasks

In order to accomplish tasks in any high-performance computing system, you need to know how to navigate
through and issue commands in a Unix or Linux operating system. In these operating systems, all
interactions you have with the computer will be done via the issuing of text based commands, as opposed
to clicking on graphical images in order to augment files or run programs.

This hands-on challenge will introduce a user to some of the most commonly used commands you will need 
to perform the most basic tasks such as navigating through the filesystem, creating directores and files,
moving and copying files, searching through files and directories, and determining your permissions and 
free disk space. Additionally, you will become familiar with how to issue a command with optional flags 
that change their behavior, as well as some of the most common options used for each command. 

When you are finished with this challenge you should be prepared to complete more advanced 
challenges ahead. 


## The Command Line

The command line (also called a command prompt) is a text interface for a computer. It is the place 
in which you type the commands that will be interpreted and executed by the computer when you enter 
them. From the command line, you can run programs and navigate through files and folders just like 
you would with Windows Explorer on Windows or Finder on MacOS. 

For example, the Windows folder in a Windows command line is `C:\Windows>`. In Unix or Linux, it 
may be `%` or `>`. In our instance it is `$`. The `$` is preceeded by information about who you are
(your username), which login node you are on (a group of processors dedicated to handling basic
interactions with the computers filesystems), and the name of the directory (file, `~` is "home") 
you are currently located in. 

On Odo, the information that represents the command line will look like this:

```
[your_id@login1.odo ~]$
```
Or
```
[your_id@login2.odo ~]$
```
> NOTE: In the following examples, replace "your_id" with whatever your user id is for logging in to 
> the system. For example, if your user id is "aaa", then your home directory is `ccsopen/home/aaa`.

During the course of this challenge, please note that the `$` you may see in the practice examples 
is NOT a part of any actual command! It is representing your command line where you should enter the
command that comes after it. 


## Issuing Commands

In general, commands are entered in the following format and issued by pressing enter after typing.

```
[command] [option flags] [file/directory/object to act upon]
```

Not all commands require the second two parts. For example, you can issue the `ls` command without
specifying a directory object and it will list the contents of whatever directory you are currently 
in. Likewise, you need not apply any optional flags. However, you can add these options to get 
information about a specific directory located elsewhere or to change the behavior of how the 
information is printed. We will see more about options for the `ls` command and other commands later. 

Option flags usually have a short hand form of single letter preceeded by a dash "-", where different
letters denote different options. The short hand notation corresponds to a long hand notation with the
full name of the same option preceeded by two dashes "--". You can put more than one letter together 
in the short hand notation after a dash to turn on multiple options at the same time. 

Here is an example of the `ls` command with the option to list directory contents in order of the time
and date at which they were last modified (most recent first), and on a specific directory that is not
necessarily the current one. If you are a brand new HPC user, issuing this command should not produce
a result, as the directory in question is currently empty with no contents to list.

```
$ ls -t /ccsopen/home/your_id
```
Again, options can be combined together for more concise commands that involve less typing. Additionally,
the options can be given in any order with the same result. For example, `ls -altr` is the same as 
`ls -l -t -r -a`.

> NOTE: Commands rarely ask for your confirmation after you hit enter. File and directory deletion
> is permanent! Always proofread before you enter a command to ensure you don't accidentally perform
> an action you did not mean to do. 

### Finding more information with the `man` command

A full explanation of the function of a command and all its available options can be found using the
`man` (for "manual") command, followed by the name of the command in question. Typing this command will 
result in the manual for the command to appear on your screen. Use your down arrow key to scroll through
the manual, or press "q" at any time to quit from the manual and return to the screen of your shell.
Try looking at the manual for the `ls` command, and when you are finished press "q" to quit. 

```
$ man ls
```

### Wildcards

When dealing with multiple files, it’s nice to be able to type a single command versus having to type
a seperate command for each file. That's where wildcards come in. They are generic characters that 
"fill in" for other characters.

- `*` means match multiple characters (0 or more)
- `?` means match a single character (1)

For example, suppose the `ls` command reports the following contents of a directory:
```
$ ls
file1   file1a  file1b  file2   file2a  file2b  file3   file3a  file3b
```
If we want to see all files that start or end with some specific text, but contain any potential single 
character, at a specific point we can augment the `ls` command with a phrase that includes `?`. 
Similarly, if we want to see a listing of all files that contain any number of characters at a specific 
point, we use the `*` character. Here are examples given the files above:

```
$ ls file1? 
file1a  file1b

$ ls file2*
file2   file2a  file2b

$ ls file?a
file1a  file2a  file3a
```

## Directories

You can think of directories as being like folders on a personal Windows or Mac computer. They are 
containers for files and other directories, and form the basis for the filesystem you can move
around in. 

### Special Directories

Every directory contains two special directory entries: ”.” and “..”. These are normally "hidden" when
you list the contents of a directory. 

`.` is a reference to the current directory. Sometimes, especially when wanting to execute (or run) a 
program or piece of code, you will see the location to the file referenced as `./my_program.exe`.
This is telling the code to look for the file "here in the current directory."

`..` is a reference to the "parent" directory, or the one "above" the one where you are located. This
winds up being important when you want to move up to a higher location in the filesystem.

`~` is usually a reference to a users "home" directory. If you see this in the path to a file, such as
`~/my_directory/my_program.exe`, this would indicate to start looking in the home directory location.

These will become more apparent later on in this exercise and in later challenges.


### Locating yourself with the `pwd` command

To see what directory you are currently in, you can issue the `pwd` command, which stands for "print 
working directory". Simply type "pwd" and press enter.

```
$ pwd

/ccsopen/home/your_id
```

The filepath that is printed after issuing this command tells you what directory in the structure of the 
filesystem you are currently located. In this case, you are in your own personal home directory that has
the same name as your personal login name, which is located inside a directory called "home" containing 
all users home directories, which is located in a directory called "ccsopen". If you are ever lost and 
can't remember where you are, simply type `pwd`.

> Typing out the paths to directories can get tiresome! The enviornment variable `$HOME` is the same as
> `/ccsopen/home/your_id`. You can use it as a shortcut in any command. For example, typing 
> `$HOME/foundational_hpc_skills` is the same as typing `/ccsopen/home/your_id/foundational_hpc_skills`. 

### Creating a new directory with the `mkdir` command

Let's start by creating your very first directory. To do this, we will use the `mkdir` command to create
two brand new directories inside of your home directory. It stands for "make directory".

```
$ mkdir new_folder new_folder2

```

Note how you can make multiple new directories at once with one command. Simply provide the names you wish
them to have separated by a space. 

### Listing directory contents with the `ls` command

In order to see the contents of your current directory, you can use the `ls` command, which "lists" the 
contents and prints them to your screen. 

```
$ ls
new_folder new_folder2
```

Now you can see the directories that you created, "new_folder" and "new_folder2". To see the contents of
these directories, you can include the name of a directory after the `ls` command. Be sure to include a 
space between the two. If the directory in question is in a different location, you can simply include 
the full path to it.

```
$ ls new_folder

$ ls /ccs/open/home/your_id/new_folder

```

Note how nothing is printed after you issue this command. This is because the directory in question is
empty. 


### Deleting directories with the `rmdir` command

Suppose you didn't mean to create two directories and you only wanted one. The `rmdir` command will allow
you to "remove a directory". Lets remove "new_folder2".

> NOTE: A directory must be empty of any files or folders for the `rmdir` command to work!

```
$ rmdir new_folder2
$ ls
new_folder
```

First we issued the command to remove new_folder2, and then issued `ls` to see the current items and confirm
that the directory we removed is gone. Note how `rmdir` did not ask for confirmation of your decsion to remove 
the directory. The system always assumes you meant to type what you typed and will do what you asked without 
checking! ALWAYS proofread before you press enter. 

> NOTE: You will not be asked for confirmation of directory or file deletion. Watch what you type!


### Adding optional flags to the `ls` command

Now lets try issuing the ls command with some options. For example, including the flag `-l` after `ls`
will list the contents in long format, hence the letter "l". Including the long option prints out the 
contents of the directory in a table format where the columns indicate: object type and permissions, number 
of links to the object, object owner, object group, object size, date and time, and the objects name.
Adding a second flag, `-h` and combining it with the first one (behind a single dash), will print the file 
and directory sizes in "human" readable format. That is, the size will be given in units of KB, MB, TB, etc. 
instead of raw bytes.

```
$ ls -lh

total 8
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder
```

Including the long option prints out the contents of the directory in a table format where the columns
indicate: object type and permissions, number of links to the object, object owner, object group, object
size, date and time, and the objects name.


Take a look at the `man` page for `ls` and try reading through all the options.  
Here is a table of some of the most frequently used options for the `ls` command. If you want more 
information about any or all of the options for a command like `ls`, don't forget you can inspect them 
with the `man` command.


### Changing directories with the `cd` command

The `cd` command is used to "change directory" and move about to different locations in the file system. 
Let's change locations and move into our new directory, and use the `pwd` command to confirm our new
location. 

```
$ cd new_folder
$ pwd
/ccsopen/home/your_id/new_folder
```

We can move back up one directory level back to our home directory like this:

```
$ cd ..
$ pwd
/ccsopen/home/your_id/
```
or like this:

```
$ cd
$ pwd
/ccsopen/home/your_id/
```
Typing `cd` by itself will take you to your home directory by default. In Unix systems, the `..` symbol 
means "the directory above the current one" and can be used to climb up higher in the filesystem no matter 
where you are located (so long as you have permission to be there!).  


## Files

Files can take as many and varied format types as they do on your personal computer: images, pictures, 
text, pdfs, programs written in various types of code, input and output data for different programs,
and executables to run your code. Now we will look at some commands to create, move, copy, and delete files. 


### Create a file with `>`

You can use `>` to tell a command to output its information to a text file instead of printing it to 
the screen. To test the use of this, lets have our `ls` command with the "long" options we used in a 
previous section be printed to a file. We will call this file "content_l.txt". First, we type the command 
we wish to print to the file, followed by `>`, and finally the name we wish the file to have.

```
$ ls -l > content_l.txt
```
Issuing `ls` again will now show that the file indeed exists in our home directory.

```
$ ls
content_l.txt new_folder
```
Lets create a second file in the same manner, but using some different options for `ls`. This time we will
add the `-h` flag so the sizes are in units that make sense. Let's call this file "contents_lh.txt"
Doing another `ls` will show that we successfully created the second file.

```
$ ls -lh > contents_lh.txt
$ ls
content_l.txt contents_lh.txt new_folder
```

Later on in a different challenge, you will learn how to create, view, and edit files using a text editing
program called `vim` or `vi` for short. This program will open a text-containing file and load its contents 
to your shell to be edited. `Vim` is similar to Word and other text editors in that you can search, copy, 
paste, add, remove, and perform other actions on the text within while it is running. For now, we will look 
at file contents with a different command. 


### View the contents of a file with `less`

A quick way to view the contents of a file is via the `less` command. This command will print the contents 
of a file to be viewed. Rather then printing the contents of the file to the command line, using `less` 
will "open" a file in your shell to allow you to inspect its contents. Let's look at the text in the two 
files we created ("content_l.txt" and "contents_lh.txt"). For files with more lines than can be displayed, 
you can scroll down through the file with the arrow keys. When you are finished examining a file, press `q` 
to exit the viewing mode.

```
$ less contents_lh.txt
```

```














total 8.0K
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder
-rw-rw-r-- 1 7vh 7vh  109 Nov 30 15:38 content_l.txt
-rw-rw-r-- 1 7vh 7vh    0 Dec  1 11:41 contents_lh.txt
contents_lh.txt (END)
```

Indeed, we created this file to hold information from the `ls` command, so viewing with `less` 
shows what we would see if we had entered that command and options on the command line instead.

### View, create, and add to files with `cat`

`cat`, short for "concatenate", is another way to create and view a file. Additionally, `cat` can also
be used to *combine* the output of already existing files. Unlike `less`, if you view a file with `cat`, 
it prints the contents directly in your terminal window as opposed to "opening" the file in a separate
viewing mode. 

To view a file, provide a single file name after the command. Try viewing the same file we looked at 
previously with `less`:

```
$ cat contents_lh.txt
total 8.0K
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder
-rw-rw-r-- 1 7vh 7vh  109 Nov 30 15:38 content_l.txt
-rw-rw-r-- 1 7vh 7vh    0 Dec  1 11:41 contents_lh.txt
```

Try entering the names of two files to see what happens:

```
$ cat contents_l.txt contents_lh.txt
total 4.0K
-rw-rw-r-- 1 7vh 7vh    0 Nov 30 15:38 content_l.txt
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder
total 8.0K
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder
-rw-rw-r-- 1 7vh 7vh  109 Nov 30 15:38 content_l.txt
-rw-rw-r-- 1 7vh 7vh    0 Dec  1 11:41 contents_lh.txt
```
We can use `cat` and the `>` from before to create a new file. Simply type:


If you want combined output to be written to a new file, use the `>` as before:

```
$ cat content_l.txt contents_lh.txt > combined.txt
```
If you want to combine files by adding the contents of one to another without creating a whole new file or 
seeing their contents printed to the command line, use two `>>`:

```
$ cat content_l.txt >> combined.txt
```
Trying viewing "combined.txt" with either command to see the result. 

Lastly, you can create a whole new file with `cat` and `>` by typing the name of a whole new file name after 
the `>` with no space. This creates a blank line where the prompt normally is to type the text you would
like to enter into the file. Once done typing, press crtl-D to finish. 

```
$ cat >new_cat_file.txt
```

### Move and rename a file with `mv`

We can move a file, or even a whole directory, from one directory to another using the `mv` command, 
short for "move". Lets move our two files we created into the directory "new_folder", which we made 
previously. Just as with the mkdir command, we can move both files simultaneously with one command
by listing them with a space between. The format should always have the new location for the items 
as the last item in the command: `mv [items to move] [new location]`

```
$ mv content_l.txt contents_lh.txt new_folder
$ ls new_folder
content_l.txt contents_lh.txt
```

First, we moved the two files into the directory, and then doing `ls` on that directory shows that the
two files are now contained within it. Likewise, if we did `cd new_folder` and then `ls` we would get 
the same result. 

We can also use the `mv` command to rename files or dirctories, using the following format:
`mv [file to be renamed] [new name]`. Lets rename the file "content_l.txt" to contents_l.txt" so that 
the names are consistent with one another. First, we will change directories into new_folder.

```
$ cd new_folder
$ ls
content_l.txt contents_lh.txt
$ mv content_l.txt contents_l.txt
$ ls
contents_l.txt contents_lh.txt
```
### Copy a file or a directory with `cp`

The command `cp` is short for "copy". You can use it to copy individual files. If copying a file or
directory in the same location as the original, you must give it a new name or you will receive an
error message. If you copy an item to a new location (by including the path in front of the name),
then the name can be kept the same. Copying a file is simple: `cp [file] [new_file]` or 
`cp [directory] [new_directory]`. Inside "new_directory", let's create a copy of the file
"contents_l.txt". 

```
$ cd new_folder
$ ls
contents_l.txt  contents_lh.txt
$ cp contents_l.txt contents_l_copy.txt
$ ls
contents_l.txt  contents_l_copy.txt  contents_lh.txt
```

Viewing the copied file with `less` will reveal that its contents are identical.

In cases where you want to copy a directory AND it's contents, use the "recursive" option, `-r`, to
include everything inside. Use this to make a copy of the directory "new_folder" and all its contents.
Be sure to use `cd` to move out of "new_folder" and back up to your home directory before this step.

```
$ cp -r new_folder other_folder 
$ ls -l
total 8
drwxrwxr-x 3 7vh 7vh 4096 Dec 13 16:37 new_folder
drwxrwxr-x 3 7vh 7vh 4096 Dec 29 10:06 other_folder
```


### Delete a file with `rm` 

The `rm` command is short for "remove". We previously created a copy of "contents_l.txt" that has 
identical information, so lets delete it using this command. An important thing to note is that the 
rm command will NOT ask you for confirmation before deleting a file unless you use the `-i` option. 
Using this flag will prompt you to confirm whether you meant to delete the item in question. Enter 
a `y` for yes, or `n` for no and press enter.

Be careful what you type when using `rm`! 

```
$ cd new_folder
$ rm -i contents_l_copy.txt
rm: remove regular file 'contents_l_copy.txt'? n
$ ls
contents_l.txt contents_lh.txt
$ rm contents_l.txt
$ ls
contents_lh.txt
```

## Finding, searching, and more information

### Locating files and directories

The `find` command is a powerful tool for locating files and directories. It has options that  
filter results based on name, location, size, date created or modified, permision status, and much more. 
In general, the syntax for find is as follows: `find [path/paths] [expression]`, where "paths" are 
the directory locations to search, and the expressions tell `find` how to filter results. We will focus 
on a few basic examples.

Entering `find` by itself will list all the files found in the current directory, as well as those in every
directory in the hierarchy below it. 

```
$ find
.
./.pki
./.pki/nssdb
./.lsbatch
./.ssh
./.bash_history
./.cache
./new_folder
./new_folder/contents_l.txt
./new_folder/contents_lh.txt
./new_folder/contents_l_copy.txt
```
> NOTE: Items in directories beginning with `.` are "hidden" files and directories that don't appear with a 
> basic `ls`. These usually relate to settings and configurations for programs and commands, and what happens 
> when you login. Although it is fine to look at the contents fo these files and directories, altering or
> removing them is NOT recommended for beginners.

If we provide the path to a directory, we will see only what is inside and recursively below that directory 
instead.

```
$ find new_folder
new_folder/
new_folder/contents_l.txt
new_folder/contents_lh.txt
new_folder/contents_l_copy.txt
```

To search for a file by name, simply include the `-name` flag. To search for a directory by name, do the same 
but also include the `-type d` flag and option.

```
$ find -name contents_lh.txt
./new_folder/contents_lh.txt

$ find -type d -name new_folder
./new_folder
```

### Finding text within files

If instead of finding a file by name, you wish to find some specific text within a file, you can use the
`grep` command. The general syntax is `grep [options] [pattern] [file]`. Check the `man` page for grep to see
the most common options. 

From the home directory, let's use `grep` to search files for some pattern. In this example, let's search the
following directory: `$HOME/foundational_hpc_skills/intro_to_unix/dir`.

```
$ cd $HOME/foundational_hpc_skills\intro_to_unix
$ ls dir
file1 file1a file1b file2 file2a file2b foo\
```
Inside is a st of files, and a directory containing more file. Each contains some text about the filename. 
We can search `file1` for the word "file" like this:

```
$ grep "file" dir/file1
This is file1
```

`grep` found the matching pattern in the file and printed the entire line that contained it. Suppose we want to
search all the files in dir for a pattern starting with "file" and ending with the letter "a". We can use a 
wildcard `*` in the directory to indicate that grep should search all the files in `dir`. However, we CANNOT use
`*` in the pattern as grep does not recognize that character as representing any other character. In the pattern,
use `.` instead like this:


```
$ grep "file.a" dir/*
dir/file1a:This is file1a
dir/file2a:This is file2a
grep: dir/foo: Is a directory
```

`grep` found the pattern in two files and printed the lines from each, indicating the file name as well. However,
`grep` did NOT search any files contained in the directory `foo\`. To do that, we must use the "recursive" option
`-r` to tell it to search all files within all directories below the one given. 

```
$ grep -r "file.b" dir/
dir/file1a:This is file1b
dir/file2a:This is file2b
dir/foo/file3a:This is file3b

```

### Identifying differences between files
The `diff` command is used to find differences between files. The syntax as is follows: `diff [file1] [file2]`. As
an example, we can look at the differences in two of the files references in the previous section. If the two files
are identical, nothing will be printed.

```
$ cd dir
$ diff file1a file2b
1,2c1
< This is file1a
<
---
> This is file2b
```

The differing contents of the two files are separated by `---`, and the arrows are used to indicate which section
corresponds to which file in order of how they were supplied in the command. Sometimes this format can be a little
difficult to interpret while reading. Using the `-y` option will print the differences in the two files side by side
in a columated format instead. 

```
$ diff file2a file1b -y
This is file2a                                                | This is file1b
```

`diff` only works on two files at a time! Supplying the names of three files or more results in an error message. 

```
$ diff file1a file1b file2a
diff: extra operand 'file2a'
diff: Try 'diff --help' for more information.
```

## Challenge #1

There are a series of files containing data about fictional users in the following directory: 
`foundational_hpc_skills/intro_to_unix/challenge`

Using whatever combination of commands seems right to you, identify the following:

a) Find the name of a user who can play the banjo and has read The Count of Monte Cristo
b) Find the name of a user who has read All Quiet on the Western Front and visited Belgium
c) Find the name of a user who has visited Cameroon and can play the Accordian

The search terms "information" and then the subsequent items that come up for each (ie: `book`), are a helpful place to 
start. (Hint: the option in `grep` for case insensitivity may also help. See the man page to find it). You could also
opt to simply view all the files instead of searching them, though this would take more time.


## Challenge #2

a) Create some files to store the answers to the previous challenge, and store them all in a new directory. Name the files
and directory whatever seems best to you. Create one additonal file that contains the result of `ls` command on the contents 
of your new directory. Make sure the resulting file orders the `ls` output in reverse order of modification time. 
(HINT: see the man page for `ls` to get the correct options).

