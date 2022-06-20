A Brief Introduction to the Vim Text Editor
=
	Adapted from Shawn Biddle's Vim Training
	https://github.com/shawncplus
	Useful Cheatsheet: https://vimsheet.com/

***********************
The Basic Stuff We Need
***********************


Modes
===

	Insert  - Adding new text (brush on canvas)
	Normal  - Starting mode, navigation and manipulation (brush off canvas)
	Command - Issue commands to vim, search, set document attributes, etc.


The Basics
===

	vim <file> - open <file> if it exists, otherwise create new <file>
	vim -R <file> -  open <file> in ReadOnly mode
	:q - Quit
	:wq - Write and quit
	:q! - Force Quit (don't save)
	:e <filename> - Open a different file without quitting Vim (or create and open a file if it doesn't already exist)



Brush to the canvas
===

	i - Enter insert mode at cursor
	o - Enter insert mode on the next line


Picking up the brush
===

	ESC
	Ctrl+[


Scanning the canvas
===

	    k
	    ^
	h <   > l
	    v
	    j


	zz - center cursor on screen

	(you can use the arrow keys as well, hjkl is good 
	because of proximity to other keys)

-------------------------------------------------------
EXERCISE SET #1

1. Quit out of this file and reopen it.
2. Write something in these parantheses (), then save and quit and reopen.
	2a. Try out the different ways of entering Insert mode for writing
3. Move around the file. Try to go all the way to the top, and all the way
   to the bottom.

-------------------------------------------------------


Visual Mode (for highlighting text)
===

	<ESC>v - Visual mode

Copy/Cut/Paste
===

	y  - Yank (i.e. copy)
	d  - "delete" (actually behaves like cut) 
	p  - paste after cursor


Undo/Redo
===

	u - undo last change
	CTRL+r - redo last undo  


Searching
===

	/  - Forward
	?  - Backward
	n  - Next result, forward in direction of search
	N  - Next result, backward in direction of search


-------------------------------------------------------
EXERCISE SET #2

1. Highlight this line with Visual mode, delete it, then undo the deletion.
2. Paste what you deleted in the parantheses (), remember that 'd' actually works like a cut operation.
	2a. Also try yanking and pasting into the parantheses.
3. Search for the word 'Bonus'. Remember that search is case sensitive. Move between each 'Bonus' in this text file
   with 'n' and 'N'

-------------------------------------------------------


******************************************************
The Advanced Stuff You Don't Need But Fun to Try
******************************************************


Getting from a to b: Motions
===
Basics: wWbBeE

	word vs. WORD
	word -- ends at a non-word chatacter, like ".", "-", or ")"
	WORD -- white-space delimited
	
	Moving by word is generally more fine-grained than moving by WORD.

	w - Forward to the beginning of next word
	W - Forward to the beginning of the next WORD
	b - Backward to the next beginning of a word
	B - Backward to the next beginning of a WORD
	e - Forward to the next end of word
	E - Forward to the next end of WORD

Try it out:
	w                             W
	----->--->---->------->---->  ----------------------------->
	These are some example words, words/with/special/separators (and also others!). Cool, huh? 
	
	
	$  - Move cursor to end of line             
	0  - Move cursor to start of line
	^  - Move cursor to first non-blank character of line
	g_ - Move cursor to last non-blank character of line

Slightly less basic: fFtT
All follow [(n)um]<verb><n(o)un> syntax

	[n]f<o> - Forward until (nth) (o)  (Inclusive)
	[n]F<o> - Backward until (nth) (o) (Inclusive)
	[n]t<o> - Forward until (nth) (o)  (Exclusive)
	[n]T<o> - Backward until (nth) (o) (Exclusive)

Try it out:
	abcdefg, abcdefg, abcdefg
	The quick brown fox jumps over the lazy dog.

Scrolling
===

	CTRL+d - Scroll down half a page
	CTRL+u - Scroll up half a page
	gg     - Go to the top of the file
	G      - Go to the bottom of the file

-------------------------------------------------------

EXERCISE SET #3

1. Move your cursor to the start and end of this line with just one or two key presses.
2. Do the scrolling exercise again where you move all the way to the top and all the way to
the bottom, but this time, go FAST!

-------------------------------------------------------


More ways to put brush to the canvas
===

	i - Enter insert mode at cursor
	I - Enter insert mode at first non-blank character
	s - Delete character under cursor and enter insert mode
	S - Delete line and begin insert at beginning of same line
	a - Enter insert mode _after_ cursor
	A - Enter insert mode at the end of the line
	o - Enter insert mode on the next line
	O - enter insert mode on the above line
	C - Delete from cursor to end of line and begin insert


Common Copy/Cut/Paste short cuts
===
	y  - Yank. Example: yw (yank word)
	yy - Yank current line
	d  - "delete" (actually behaves like cut) Example: dw (delete word)
	dd - "delete" current line
	p  - paste after cursor
	P  - paste before cursor

More Searching
===

	/  - Forward
	?  - Backward
	*  - Word under cursor - forward
	#  - Word under cursor - backward
	n  - Next result, forward in direction of search
	N  - Next result, backward in direction of search



Comments with Visual Block Mode
===
	1) enter Visual Block Mode with : CTRL V
	2) select lines
	3) enter Insert Mode with : SHIFT I
	4) make changes to be applied to all selected lines
	5) ESC


Delete inside
===

	di<enclosing character>  - "Delete inside"

	Example:

	int a;
	for (a = 0; a < 100; a += 1){
		printf("a is:  %d\n", a);
	}


Tabs
===

	:tabe <filename> - open a new file in a tab
	gt - go to next tab
	gT - go to previous tab

Panes
===

	:sp (or) CTRL+w s - horizontally split current pane
	:vsp (or) CTRL+w v - vertically split current pane
	CTRL+w CTRL+w - switch between current panes in the current window
	CTRL+w c - close current pane


--------------------------------------------------
EXERCISE SET #4

1. Open a new tab and switch between them.
2. Have two tabs open, and open four panes in each tab.
	a. Try writing something in each pane and save it.
---------------------------------------------------
