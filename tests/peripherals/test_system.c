#include "logging.h"
#include "system.h"

int main(void)
{
   // Set up system hardware
   setup_hardware();
   print("Device successfully started!\n");

   // Put the CPU into deep sleep forever
   while (true)
      system_enter_deep_sleep_mode();

   // Should never reach this point
   return 0;
}
