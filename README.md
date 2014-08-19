mod\_timestamp
=============

This lib provides a way to print time/date-stamped messages to the console.  It
uses clock\_gettime() to find the time elapsed from a start\_time.  This time
is further processed into a HH:MM:SS.<nanoseconds> format before combining it
with a message and printing it to stdout.

The project includes an example test suite, mytimer.c.

Building
========

To build the project:
	gcc -lrt -o timerTest mytimer.c mod\_timestamp.c
