/** 
 * @file timer.c
 * @brief This prog tests clock_gettime() func
 * 			To use, first, create a global of type stampTimer_t called
 * 			start_time.  This will hold 'time zero' or the start of the timer.
 * 			Next, load this struct by calling startTimer().  Finally, call
 * 			printStamp with a string and it will print the string with a
 * 			timestamp representing the elapsed time since start_time.
 *
 * @author Harlan Shoop
 * @version 0.1
 * @date 2014-08-18
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#include "mod_timestamp.h"


/* ****************************************************************** */
/** 
 * @brief Calculates elapsed time since start_time
 * 
 * @return elapsed time type stampTimer_t (timespec)
 */
/* ****************************************************************** */
stampTimer_t diffTime( void )
{
	stampTimer_t gettime_now;
	stampTimer_t diff_time;

	clock_gettime( CLOCK_REALTIME, &gettime_now );
	diff_time.tv_nsec = gettime_now.tv_nsec - start_time.tv_nsec;
	diff_time.tv_sec = gettime_now.tv_sec - start_time.tv_sec;

	return diff_time;

} // diffTime()

/* ****************************************************************** */
/** 
 * @brief Print a time stamped ts_msg; time down to the nanosecond
 * 
 * @param msg Message to print
 */
/* ****************************************************************** */
void printStamp( char * msg )
{
	int hrs, min, min_left, sec, sec_left, nsec;
	stampTimer_t stamp;
	stamp = diffTime();
	// Determine hours and minutes
	nsec = stamp.tv_nsec;
	sec = ( int )stamp.tv_sec;
	hrs = sec / SECS_PER_HR;
	min = sec / SECS_PER_MIN;
	min_left = min % SECS_PER_MIN;
	sec_left = sec % SECS_PER_MIN;

	printf( "%02d:%02d:%02d.%09d: %s\n", hrs, min_left, sec_left, nsec, msg );
} // printStamp()

/* ****************************************************************** */
/** 
 * @brief Initializes the global start_time
 */
/* ****************************************************************** */
void startTimer(void)
{
	// start_time must be a global
	clock_gettime( CLOCK_REALTIME, &start_time );
} // startTimer()

