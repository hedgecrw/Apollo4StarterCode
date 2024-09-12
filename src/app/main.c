#include "logging.h"
#include "rtc.h"
#include "system.h"

int main(void)
{
   // Set up the system hardware
   setup_hardware();

   // Initialize required peripherals and start up the RTC
   print("Initializing peripherals...\n");
   rtc_init();
   rtc_set_time_to_compile_time();
   system_enable_interrupts(true);
   print("All peripherals initialized!\n");

   // Loop forever doing something
   while (true)
   {
      // Deep sleep until there is something to do
      print("Going to sleep...\n");
      system_enter_deep_sleep_mode();
   }

   // Should never reach this point
   system_reset();
   return 0;
}
