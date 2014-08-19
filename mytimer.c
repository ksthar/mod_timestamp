/** 
 * @file mytimer.c
 * @brief Test app for mod_timestamp.c
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
 * @brief Main loop
 * 
 * @return pass/fail
 */
/* ****************************************************************** */
int main(void)
{
	// initialize start_time
	startTimer();

	int total, loops;				/**< loop vars				*/
	long int timer_nsecs = 1200000; /**< Timer in nanoseconds 	*/
	stampTimer_t time_diff;			/**< Elapsed time for timer	*/

	sprintf( ts_msg, "*** Welcome to the timer test ***" );
	printStamp( ts_msg );
	sprintf( ts_msg, " " );
	printStamp( ts_msg );
	sprintf( ts_msg, "Every line is printed with a time stamp = hh:mm:ss.nnnnnnnnn" );
	printStamp( ts_msg );
	sprintf( ts_msg, "--------------------------------" );
	printStamp( ts_msg );
	sprintf( ts_msg, "First, the nanosecond timer test." );
	printStamp( ts_msg );
	sprintf( ts_msg, "--------------------------------" );
	printStamp( ts_msg );

	sprintf( ts_msg, "Number of nanoseconds in timer: %d", (int)timer_nsecs );
	printStamp( ts_msg );

	sprintf( ts_msg, "Start of timer: %lu", start_time.tv_nsec );
	printStamp( ts_msg );

	// Check if timer_nsec is < rollover...otherwise, we'll never
	// reach the timer--just keep rolling over
	if( timer_nsecs >= 100000000 )
	{
		sprintf( ts_msg, "Error: timer greater than 1 sec. Exiting..." );
		printStamp( ts_msg );
		return 1;
	}

	sprintf( ts_msg, "Entering loop..." );
	printStamp( ts_msg );
	loops = 0;
	while( 1 )
	{

		time_diff = diffTime();
		if( time_diff.tv_nsec > timer_nsecs )
		{
			sprintf( ts_msg, "Hit the time at %lu after %d loops.", time_diff.tv_nsec, loops );
			printStamp( ts_msg );
			break;
		} // timer triggered
		loops++;
	} // while 1

	sprintf( ts_msg, "--------------------------------" );
	printStamp( ts_msg );
	sprintf( ts_msg, "Next, we'll print every 30 sec" );
	printStamp( ts_msg );
	sprintf( ts_msg, "--------------------------------" );
	printStamp( ts_msg );

	loops = 0;
	total = 5;
	sprintf( ts_msg, "Entering loop..." );
	printStamp( ts_msg );
	while( loops < total )
	{
		sleep( 30 );
		loops++;
		sprintf( ts_msg, "Note the time at loop %d of %d", loops, total );
		printStamp( ts_msg );
	} // while loops

	sprintf( ts_msg, "Done." );
	printStamp( ts_msg );

	return 0;

} // main
