# Funny-Star-Mouse
Imagine a mouse that walks within a 50 by 50 array. The mouse holds a pen in one of two positions: up or down. While the pen is up, the mouse does not write anything. While the pen is down, the mouse marks each array location it passes by. You will read a sequence of commands (one per line) from standard input (I suggest using an input textfile and use input redirection as you did in Lab 4) and walk the mouse. The mouse always starts at location (0,0) with its pen up. Possible commands are:
* 1- Penup
* 2- Pen down
* 3- Turn right
* 4- Turn left
* 5,n- Move forward n spaces
* 6 Print the array, putting an asterisk for marked locations, putting a space for unmarked
locations. However put one extra space character between consecutive columns.
* 9 End of data marker.

For example, the following set of commands should draw a 10 by 10 array as:
********** ** ** ** ** ** ** ** ** **********
2

5,10

3

5,10

3

5,10

3

5,10

1

6

9
