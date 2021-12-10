# Introduction to Python

## What is Python?

Insert blurb about what Python is and why it's cool/useful, will come back to this last

Before getting started, make sure you have a fresh Unix terminal open.

We will specifically be using Python3 in this guide.

Two of the most common ways to use Python are:

1. Using an interactive session within your terminal
2. Writing/Launching Python scripts (typically ".py" files)

Part one of the basics will be done in interactive mode, while part two will be in scripting mode (as what is covered in the part two subsections are better suited in a scripting environment).

## The Basics - Part One

Before you start writing your own Python scripts, it is recommended to first test things in an interactive session.
This will allow you to see output in real-time and let you fix things dynamically if error messages arise.
Unless otherwise stated below a specific example, it is encouraged to follow along in your own interactive Python session through the entire walkthrough.

### Line Syntax

To get started, all you have to do is launch an interactive Python shell by typing "python3" in your terminal:

```python
$ python3

Python 3.7.6 (default, Aug 13 2021, 16:40:31) 
[Clang 12.0.5 (clang-1205.0.22.11)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>>
```

The ">>>" symbol is the prompt of the interactive Python interpreter, meaning that the interpreter is ready for Python code to be typed in.
Anything you type in, until you exit your interactive shell, will be executed with Python.
The code will be executed on a line-by-line basis, and a line will be executed after pressing Enter/Return.
To end a statement in Python, you do not have to type in a semicolon or other special character, you just need to press Enter/Return.

First, let's test things out by making Python say "Hello!" to us using the `print` function:

```python
>>> print("Hello!")
Hello!
>>>
```

Congratulations, you just used Python for the first time in this walkthrough!
As it has finished printing out "Hello!", the interactive prompt is now displaying ">>>" again and waiting for you to tell it what to do next.
Let's use the `print` function again to print out multiple things at once that are side-by-side:

```python
>>> print("I am on the left!", "I am on the right!")
I am on the left! I am on the right!
>>>
```

Under certain circumstances, your lines may begin with "..." (called "continuation lines"), indicating that the interpreter has not run anything yet and is waiting for you to input something else or "finish" the line.
To see this, we can explicitly span a single Python statement across multiple lines by using the `\` symbol at the end of a line.
Let's do this by modifying our above `print` statement example:

```python
>>> print("I am on the left!", \
... "I am on the right!")

I am on the left! I am on the right!
```

Even though we split the single statement across multiple lines, Python still ran the code as if it were all on the same line.
Therefore, you can think of the `\` symbol as just extending any given line.
Using `\` can be helpful if you are typing a lot of code on a single line and would like to make it more "human-readable" in a text editor for example.
The reason why you see "..." is because the interpreter waited for you to tell it what to do next.
In this case, it was waiting for you to "finish" the `print` function by submitting the final closing `)`.

Now that you've seen how to split a single Python statement across multiple lines, let's try to combine multiple statements into a single line.
We can combine both statements into a single line using the `;` symbol.
Consider the following code:

```python
>>> print("I am on top") ; print("I am on bottom")
I am on top
I am on bottom
```

The `;` symbol is a shortcut for executing multiple statements on a single line, rather than having to code two lines separately.
This can be useful for consecutive lines that are short and succinct, or for consecutive lines that may be related to each other.
To the Python interpreter, the above example would just look like:

```python
>>> print("I am on top")
>>> print("I am on bottom")
```

Some final syntax that we need to cover before moving on is Python "comments".
Comments are not interpreted by Python and are used to clarify code -- usually they act as notes to yourself or others to explain what a piece of code may be doing (they are otherwise hidden).
Comments in Python start with the hash character `#` (also known as "pound" or "hashtag"), which affects all the text you type in afterward.
A comment may appear at the start of a brand new line or following pieces of code.
However, the `#` symbol enclosed by a pair of `"` or `'` is just a hash character and has no effect.
For example, consider the following code:

```python
>>> # this is a comment
>>> print("Comments are hidden") # this is also a comment
Comments are hidden
>>> print(" # this is not a comment because enclosed")
 # this is not a comment because enclosed
```

Comments are used heavily throughout this guide and, other than the above example, you do not have to type in the comments yourself while you go through the examples -- they are mainly there for you to read.

> Note: As you will see when we discuss scripting (insert section here), you can enclose multiple lines in a pair of `'''` or `"""` (three single quotes or three double quotes) to comment out entire blocks of lines.

Now that we have covered the some of the basic syntax, let's dig deeper and show off what Python can do with numbers.

### Numbers and Variables

One of the most common things Python is used for is being a *fancy* numerical calculator.
Python behaves similarly to other languages when performing arithmetic, using the operators `+,-,*,/` for addition, subtraction, multiplication, and division:

```python
>>> 2 + 2        # addition
4
>>> 0 - 1        # subtraction
-1
>>> 2 * 3        # multiplication
6
>>> 10 / 5       # division
2
>>> 3 ** 2       # exponents/powers (e.g., 3 to the power of 2)
9
>>> (1 + 2) * 4  # parentheses have priority
12
```

As is the case with most coding languages, integers (-2, -1, 0, 1, etc.) are of the type `int` and rational numbers (-2.0, -1.3, 0.2, 1.4, etc.) are of the type `float`. Mixing `float` and `int` numbers typically results in converting everything to a `float`.
Using the `/` division operator to divide integers also results in a `float`, unless you use the `//` "floor" division operator:

```python
>>> type(1.0) # check type of 1.0
<class 'float'>
>>> type(1)   # check type of 1
<class 'int'>
>>> 4.2 * 2   # mixed inputs results in a float answer
8.4
>>> 17 / 3    # integer division results in a float answer
5.666666666666667
>>> 17 // 3   # integer division with "//" floors the answer to an integer
5
```

You can use the equal sign `=` to assign a value to a variable:

```python
>>> width = 2.0  # storing a value into a variable called "width"
>>> height = 3.0 # storing a value into a variable called "height"
>>> area = width * height
>>> print(area)  # explicitly print out a variable
6.0
>>> area         # prints out a variable (only possible in interactive mode)
6.0
```

A variable name can only contain alpha-numeric characters and underscores (A-Z, 0-9, and _ ) and cannot start with a number.
Additionally, a variable name is also case-sensitive and must be one continuous set of characters without any spaces, or you will get an error.
If you try and access a variable that does not exist, you will also get an error:

```python
>>> print(area)      # print out our old variable
6.0

>>> print(Area)      # slightly misspell our variable (case-sensitive)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'Area' is not defined

>>> width new = 4.0  # try to set a variable name with a space in it
  File "<stdin>", line 1
    width new = 4.0
            ^
SyntaxError: invalid syntax
```

> Note: Soon you will see that variables aren't just limited to numbers, they can store other types of data as well.

For a more advanced approach, here are some handy tricks when using variables:

```python
>>> x, y, z = 1, 2, 3  # set multiple variables at once to different values
>>> print(x,y,z)
1 2 3
>>> a = b = c = 4      # set multiple variables at once to the same value
>>> print(a,b,c)
4 4 4
>>> e = 5
>>> f = 6
>>> print(e,f)
5 6
>>> e, f = f, e        # swap two variables
>>> print(e,f)
6 5
```

One last trick that not many people are taught is that, in interactive mode, the last printed expression is assigned to the internal variable name `_`.
This comes in handy when you are using Python as a quick calculator, for example:

```python
>>> tax = .10      # set tax to ten percent
>>> price = 100.0  # price is $100
>>> tax * price    # additional price, gets assigned to "_" variable
10.0
>>> _              # print out what "_" currently is
10.0
>>> price + _      # total price, also resets "_" variable
110.0
>>> _
110.0
```

This variable should be treated as read-only by the user.
Do not try to explicitly assign a value to `_`, for you would create an independent local variable with the same name that would override the built-in variable with its "magic" behavior.

Let's continue the Python "magic" by moving on to strings!

### Strings and Slicing

A string in Python is a sequence of characters that usually represent a form of text.
In other coding languages, such as Fortran and C, text is usually stored in some form of "character" or "char" datatype.
Python, however, does not have a character datatype.
Instead, a single character in Python is simply a "string" datatype called `str` with length 1 (a string with two characters would be of length 2, etc.).
Like with numbers, Python also has the ability to manipulate strings.

We have already used a few strings in this walkthrough when we used the `print` function, but you can also assign strings to variables using `=`.
To create a string in Python, all you have to do is enclose it in a pair of quotation marks, either a pair of single quotes `'...'` or double quotes `"..."`.
The choice between the two is usually personal preference; however, `"` is helpful when the string you are dealing with already has a `'` in it, and vice versa:

```python
>>> x = "Hello"                       # double quote example
>>> y = 'Hello'                       # single quote example
>>> x==y                              # check if "x" is equivalent to "y"
True
>>> no_error_1 = "You're cool"        # double quotes enclosing a single quote
>>> error_1 = 'You're cool'           # using single quotes instead (error)

  File "<stdin>", line 1
    error_1 = 'You're cool'
                    ^
SyntaxError: invalid syntax

>>> no_error_2 = ' No "i" in "Team" ' # single quotes enclosing double quotes
>>> error_2 = " No "i" in "Team" "    # using double quotes instead (error)

  File "<stdin>", line 1
    error_2 = " No "i" in "Team" "
                    ^
SyntaxError: invalid syntax
```

For a more advanced approach, you can explicitly "escape" the error messages seen above by using either `\'` or `\"` in problematic areas:

```python
>>> error_1 = 'You\'re cool'           # use \ symbol to escape ' (fixes error)
>>> error_2 = " No \"i\" in \"Team\" " # use \ symbol to escape " (fixes error) 
```

Similar to numbers, strings also can be manipulated using the `+` and `*` operators.
More specifically, the `+` operator combines (or concatenates) two strings, while the `*` operator can be used to repeat a string if used with a number:

```python
>>> "gg" + "ez"              # combining two strings using +
'ggez'
>>> 3 * "yes"                # repeat a string using *
'yesyesyes'
>>> ( 3 * "yes" ) + "no"     # repeat a string and combine
'yesyesyesno'
```

One shortcut that is only usable when dealing with two strings outside of variables is the ability to automatically combine them without having to use the `+` operator:

```python
>>> "Good luck " "have fun"  # combine two literal strings
'Good luck have fun'
>>> x = "Good luck "
>>> y = "have fun"
>>> x y                      # try with variables instead (error)
  File "<stdin>", line 1
    x y
      ^
SyntaxError: invalid syntax

>>> x + y                    # combining string variables must use +
'Good luck have fun'
```

As you will see with lists further below, one cool thing about strings is that you can "slice" them to extract specific portions of the string.
Slicing is heavily used throughout Python code, especially in data analysis, data mining, plotting, sorting, and much more.
"Indexing" is a subset of slicing that only extracts one character from a string, while "slicing" can extract multiple characters at once (i.e., multiple indices).

As is the convention with most of Python, indexing starts at 0 instead of 1, which can be confusing at times (especially for those transitioning from Fortran).
The first character in a string has index 0, the second character has index 1, and so on and so forth.
To find the full length of a string you can use the `len` function.
Let's see this in some examples.
To start, you must put these indices in square brackets `[ ]`:

```python
>>> z = "abcdefghij"  # make a test string of length 10
>>> len(z)
10
>>> z[0] # character in index/position 0
'a'
>>> z[1] # character in index/position 1
'b'
>>> z[9] # character in index/position 9
'j'
```

> Warning: We will be using the variable "z" for the next couple examples, so be sure not to overwrite it!

Note that in our example we had 10 letters, but since indexing starts from 0, the final letter in the string is index 9.
You can also use negative indices to start at the end of the string.
Therefore, you can think of using negative indices as reading from "right to left" instead of "left to right":

```python
>>> z[-1]  # character in position -1 (equivalent to position 9)
'j'
>>> z[-2]  # character in position -2 (equivalent to position 8)
'i'
```

Negative indices can be helpful when you don't know how long a string is, but you know that you want specific characters located at the end of the string, however long the string may be.

Transitioning from "indexing" to "slicing", you can use the `:` operator inside of `[ ]` to pick a range of indices (inserted on either side of the `:`).
Note that when using `:`, the left side is *inclusive* while the right side is *exclusive*.
Therefore, for a desired range, this results in a syntax of `[desired start index : desired end index + 1 ]`.
For example, using our `z` string variable of length 10:

```python
>>> z[0:10]       # slices indices 0-9 (the entire string of length 10)
'abcdefghij'
>>> z[0:5]        # slices indices 0-4 (the first five characters)
'abcde'
>>> z[1:5]        # slices indices 1-4
'bcde'
>>> z[1 : (4+1)]  # slices indices 1-4 (same as above, but with math)
'bcde'
```

> Note: When performing math inside of `[ ]` on indices, the numbers must be integers and/or the math should result in an integer.

Instead of explicitly indicating the start/end of a slice with indices, you can choose to leave a side of the `:` blank.
Leaving the left side blank means that you want the slice to begin at the start of the string, while leaving the right side blank means you want the slice to stop at the end of the string.
Therefore, leaving **both** sides blank (i.e., `[ : ]`) indicates that you just want the entire string returned.
Going back to our `z` variable again:

```python
>>> z[:]    # return the entire string
'abcdefghij'
>>> z[2:]   # slice from index 2 to the end of the string
'cdefghij'
>>> z[:8]   # slice from the beginning of the string until index 7
'abcdefgh'
>>> z[:-1]  # slice the entire string ignoring the last character
'abcdefghi'
>>> z[:-2]  # slice the entire string ignoring the last two characters
'abcdefgh'
```

Because of the left side of `:` being included and the right side being excluded, this makes sure that `z[ : index ] + z[ index : ]` is always equal to `z`:

```python
>>> z[:2]
'ab'
>>> z[2:]
'cdefghij'
>>> z[:2] + z[2:]
'abcdefghij'
>>> z[:4] + z[4:]
'abcdefghij'
```

A lot of the techniques we use to manipulate strings are also used for more grand and overarching types of data, which is what we'll be covering next.

### Lists

Now that you know a few of the micro-scale datatypes, the next thing we are going to cover is how to group data -- specifically by using something in Python called a "list".
Lists are defined as a "compound" datatype and are able to group together both numbers and strings, either individually or in a mix.
The data contained in a list are comma separated and enclosed by square brackets.
Here are some examples:

```python
>>> blank_list = []                       # create a "blank" list of length 0
>>> tiny_list = ['hola']                  # create a list of length 1
>>> num_list = [0, 1, 2, 3.0, 4.0]        # create a list of numbers of length 5
>>> str_list = ['hey', 'hi', 'yo']        # create a list of strings of length 3
>>> mixed_list = [1, 7, 'cool', 'groovy'] # create a mixed list of length 4
```

> Warning: We will be using the above lists in the next couple examples, so be sure not to overwrite them!

Lists obey some of the same operations we already covered for strings, such as combining and slicing:

```python
>>> combined_list = num_list + str_list  # combining two lists into a new list
>>> combined_list[:]                     # return/slice entire list
[0, 1, 2, 3.0, 4.0, 'hey', 'hi', 'yo']
>>> combined_list[0]                     # return/slice first entry in list
0
>>> combined_list[-1]                    # return/slice final entry in list
'yo'
>>> combined_list[0:5]                   # return/slice first 5 entries
[0, 1, 2, 3.0, 4.0]
>>> len(combined_list)                   # return length of the list
8
```

Unlike with strings, you can modify a specific entry in a list with slicing/indexing:

```python
>>> squares = [0, 1, 4, 9, 16, 25, 'temp'] # create a list of "squared" values  
>>> squares[6]                             # final entry does not fit pattern
'temp'
>>> squares[6] = 36                        # modify data of the final entry
>>> squares                                # inspect the modified list
[0, 1, 4, 9, 16, 25, 36]
```

This slicing ability can also be used to modify sections of lists, or be used to completely remove sections:

```python
>>> dummy = ['a', 'b', 'c', 1, 2, 3, 'g', 'h', 'i'] # create a new list
>>> dummy[3:6]                                      # identify problem area
[1, 2, 3]
>>> dummy[3:6] = ['D', 'E', 'F']                    # replace problem area
>>> dummy                                           # inspect modified list
['a', 'b', 'c', 'D', 'E', 'F', 'g', 'h', 'i']
>>> dummy[3:6] = []                                 # decide to remove that area
>>> dummy                                           # inspect the list again
['a', 'b', 'c', 'g', 'h', 'i']
>>> dummy[:] = []                                   # remove all entries
>>> dummy
[]
```

As you will see further below, we will be utilizing lists a fair amount later in this walkthrough.

This concludes the first half of the basics walkthrough -- the "interactive shell" portion.
Although what's covered below is also considered part of "the basics," the topics below are better suited in a scripting environment.
Hence, we will be transitioning out of the Python interactive shell we have been using into writing and running Python scripts instead.

## The Basics - Part Two

The second half of this walktrhough is done in scripting mode for convenience.
Luckily, all of what we covered above still applies when running Python scripts, but there are a few changes of note.
First, since everything in a `.py` file is assumed to be run with Python, there is no need for the `>>>` symbol to be at the beginning of your lines of code.
Similarly, you will no longer need `...` at the beginning of your lines to indicate continuation lines.
We also now gain the ability to comment out multiple lines at once using `'''`, which is a nice bonus.
Everything else we discussed previously goes unchanged, yay!

> Note: Technically, you are able to do `'''` in interactive mode, but it is much more cumbersome, so we did not cover it.

To run Python scripts using Python 3, it's as simple as executing `python3 file.py`, but first we need to create a file.
By now you will have covered the VIM challenge [insert link to VIM challenge here], so you can use VIM or your favorite text editor to create a file called `first_script.py`.

Once you have created/opened this file, it's time to fill it with some code.
Entering code into a Python file works just like entering it into the interactive shell, just without the `>>>`.
And, just like before, it is executed line-by-line, so to enter a new Python statement or piece of code, just move on to the next line.
A blank line in your file will cause no harm, as it just means you are not trying to execute code on that line.
Blank lines can be useful for spacing out your file and organizing your code.
For testing purposes, let's fill out `first_script.py` with the following code:

> WARNING: WILL REPLACE THIS PART WITH A PREMADE SCRIPT SO THEY DONT HAVE TO MAKE THEIR OWN

```python
 # top of the file

'''
Showing off commenting out multiple lines.
Sometimes comments of this nature are used
to provide a description of the file at
the top of the file.
They can span multiple lines when enclosed
by a pair of three single quotes.
'''

print("Hello from your first script!")

 # add some numbers
x = 8.675
y = 3.09
z = x + y

 # print out some output
print("Jenny has ", z, " apples")
```

After you have filled in your file with code, you can run it by executing the following in your terminal:

```bash
python3 first_script.py
```

You should then see the following output displayed in your terminal:

```
Hello from your first script!
Jenny has 11.765 apples
```

If you see the above output, great, you are now prepared to continue this walkthrough.
Now that you know how to launch a Python script, let's cover the remaining topics in "the basics".

> Note: The topics and techniques below can still be used in interactive mode, but are better suited in a scripting environment.

### Loops and Indentation

for loops / while loop section, teaching how to indent

### if-statements

if statement stuff goes here

### functions

function stuff goes here

### importing libraries (may skip)

importing example like numpy with arrays (may skip)

## Challenges

challenge exercises relating to the topics we covered throughout the walkthrough, will hyperlink to a given section that the challenge relates to (I have challenges ready, will copy paste them in at the end)(will have solutions in a separate directory)

## Additional Resources

Blurb/bullet point list of additional resources

 

