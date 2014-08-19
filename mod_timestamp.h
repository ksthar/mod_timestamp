/** 
 * @file mod_timestamp.h
 * @brief Header file for mod_timestamp.c
 * @author Harlan Shoop
 * @version 0.1
 * @date 2014-08-18
 */

#define		SECS_PER_MIN	60				/**< seconds per minute					*/
#define		SECS_PER_HR		3600			/**< seconds per hour					*/

typedef struct timespec stampTimer_t;		/**< timespec struct over and over...	*/

// prototypes
stampTimer_t diffTime( void );
void printStamp( char *msg );
void startTimer( void );

// globals
static stampTimer_t start_time;				/**< this holds time 'zero' timer fcns 	*/
char ts_msg[ 255 ];							/**< message string for time stamp 		*/
