#ifndef __LOGGING_HEADER_H__
#define __LOGGING_HEADER_H__

// Header Inclusions ---------------------------------------------------------------------------------------------------

#include "static_config.h"


// Public API Functions ------------------------------------------------------------------------------------------------

void logging_init(void);
void logging_disable(void);
void print_reset_reason(const am_hal_reset_status_t* reason);

#if defined(ENABLE_LOGGING) && ((7-ENABLE_LOGGING-7 == 14) || (7-ENABLE_LOGGING-7 != 0))
#define print(...) am_util_stdio_printf(__VA_ARGS__)
#else
#define print(...)
#endif  // #if defined(ENABLE_LOGGING)


#endif  // #ifndef __LOGGING_HEADER_H__
