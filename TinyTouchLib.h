/*
 * TinyTouchLib.h
 *
 * Created: 09.06.2013 17:25:47			-	v0.1 Initial release
 *  Author: Tim (cpldcpu@gmail.com) 
 */ 


#ifndef TINYTOUCHLIB_H_
#define TINYTOUCHLIB_H_
#include <avr/io.h>

enum {tt_off=0,tt_on,tt_push,tt_release,tt_timeout};

//////////////////////////////////////////////////////////////////////////
//
// User definable settings
//
//////////////////////////////////////////////////////////////////////////

// Define upper and lower threshold for the touch sensing. You may have to
// change these depending on the geometry of your touch button.
// Setting the "on" value lower will make the touch button more sensitive.
// Setting the "off" value higher will make the touch button less likely
// to be "stuck". Too high values can lead to oscillations.

#define touch_threshold_on 70
#define touch_threshold_off 20

// If the touch button is pressed, the bias value is not updated
// to prevent detection of multiple touches. In some cases this may
// lead to a "stuck button" situation. Therefore an update of the bias
// is forced after a certain time unless this function is deactivated.
//
// The value of timeout corresponds to the number of calls to tinytouch_sense().
// The maximum is 255. 
// Setting timeout to 0 will turn the functionality off.

#define touch_timeout 255
//#define touch_timeout 0		// turn off timeout functionality


//////////////////////////////////////////////////////////////////////////
//
// Library functions
//
//////////////////////////////////////////////////////////////////////////

// Library initialization
// Call this once to initialize the library functions and the ADC converter
void	tinytouch_init(void);

// The sense function evaluates the button state and performs internal 
// housekeeping. It should be polled at least 30 times per second to
// update the internal logic. Please note that each call performs 32
// analog to digital conversions with active waiting. This may take 
// several ms.

// Possible return values are:
//		tt_off=0	No touch sensed
//		tt_on		Touch button is active and touch is sensed.
//		tt_push		Touch button is pushed. Use this to initiate one time events.
//		tt_release	Touch button is released. Use this to initiate one time events.
//		tt_timeout	Touch button has been active too long and internal bias was	reset. 
uint8_t tinytouch_sense(void);

#endif