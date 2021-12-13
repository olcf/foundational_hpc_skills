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


pwd, mkdir, rmdir, cd, ls, cp, mv, chmod, rm, find, grep, diff, head, tail, df, du, man


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

> NOTE: In the following examples, replace "your_id" with whatever your user id is for logging in to the system
> For example, if your user id is "aaa", then your home directory is `ccsopen/home/aaa`.

```
$ ls -t /ccsopen/home/your_id
```
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

## Directories

You can think of directories as being like folders on a personal Windows or Mac computer. They are 
containers for files and other directories, and form the basis for the filesystem you can move
around in. 

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

<br>
<center>
<img src="images/UnixPermissions.gif" style="width:80%">
</center>
<br>

Take a look at the `man` page for `ls` and try reading through all the options.  
Here is a table of some of the most frequently used options for the `ls` command. If you want more 
information about any or all of the options for a command like `ls`, don't forget you can inspect them 
with the `man` command.


### Changing directories with the `cd` command

The `cd` command is used to "change directory" and move about to different locations in the file system. 
Let's change locations and move into our new directory, and use the `pwd` command to confirm our new
location. 

```
$cd new_folder
$pwd
/ccsopen/home/your_id/new_folder

```

We can move back up one directory level back to our home directory like this

```
$cd ..
$pwd
/ccsopen/home/your_id/
```

In Unix systems, the `..` symbol means "the directory above the current one" and can be used to climb up 
higher in the filesystem no matter where you are located (so long as you have permission to be there!).
If you ever want to return to your home directory, simply type and enter `cd` by itself. 


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


### View the contents of a file with `cat`

A quick way to view the contents of a file is via the `cat` command, which is short for "concatenate". This 
command will print the contents of a file to be viewed. Let's look at the text in the two files we created
"content_l.txt" and "contents_lh.txt". 

```
$ cat content_l.txt
total 4.0K
-rw-rw-r-- 1 7vh 7vh  109 Nov 30 15:38 content_l.txt
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder

$ cat contents_lh.txt
total 8.0K
-rw-rw-r-- 1 7vh 7vh  109 Nov 30 15:38 content_l.txt
-rw-rw-r-- 1 7vh 7vh  170 Dec  1 11:41 contents_lh.txt
drwxrwxr-x 2 7vh 7vh 4.0K Nov 23 11:09 new_folder
```
Indeed, we created this file to hold various incantation of the `ls` command, so printing them with `cat` 
shows what we would see if we had entered those same command options on the command line instead.

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
`cp [directory] [new_directory]`. 


In cases where you want to copy a directory AND it's contents 


### Delete a file with `rm` 

The `rm` command is short for "remove". We previously created a copy of "contents_l.txt" that has 
identical information, so lets delete it using this command. An important thing to note is that the 
rm command will NOT ask you for confirmation before deleting a file unless you use the `-i` option. 
Using this flag will prompt you to confirm whether you meant to delete the item in question. Enter 
a `y` for yes, or `n` for no and press enter.

Be careful what you type when using `rm`! 

```
$ rm -i contents_l_copy.txt
Including the long option prints out the contents of the directory in a table format where the columns
indicate: object type and permissions, number of links to the object, object owner, object group, object
size, date and time, and the objects name.
rm: remove regular file 'contents_l_copy.txt'? n
$ ls
contents_l.txt contents_lh.txt
$ rm contents_l.txt
$ ls
contents_lh.txt
```

### Challenge

Put together what you have learned so far to acomplish the following task: create a new directory in 
your home directory and in it create two files. Make one contain the output of `ls` where the contents
two files. One should contain the output of the ls command

Finish this part with a challenge that requires users to put together multiple commands theyve learned/
