#include "logging.h"
#include "system.h"

int main(void)
{
   // Set up system hardware
   setup_hardware();

   // Output a different line every second
   print("Starting logging test!\n");
   while (true)
      for (int i = 0; i < 1000; ++i)
      {
         print("Seconds elapsed: %d\n", i);
         system_delay(1000000);
      }

   // Should never reach this point
   return 0;
}
