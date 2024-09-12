#ifndef __STATIC_CONFIG_HEADER_H__
#define __STATIC_CONFIG_HEADER_H__

// Application Configuration -------------------------------------------------------------------------------------------

#ifdef AM_DEBUG_PRINTF

#define ENABLE_LOGGING  1

#endif


// Common Header Inclusions --------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include "am_bsp.h"
#include "am_util.h"
#include "pinout.h"


// Common Application Definitions --------------------------------------------------------------------------------------

#ifdef AM_DEBUG_PRINTF
extern void vAssertCalled(const char * const pcFileName, unsigned long ulLine);
#define configASSERT0( x ) if( ( x ) != 0 ) vAssertCalled( __FILE__, __LINE__ )
#define configASSERT1( x ) if( ( x ) != 1 ) vAssertCalled( __FILE__, __LINE__ )
#else
#define configASSERT0( x ) x
#define configASSERT1( x ) x
#endif


// Interrupt Priorities ------------------------------------------------------------------------------------------------

#define RTC_ALARM_INTERRUPT_PRIORITY                    (AM_IRQ_PRIORITY_DEFAULT)


#endif  // #ifndef __STATIC_CONFIG_HEADER_H__
