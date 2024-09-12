# Apollo4 Starter Code

This code base can quickly be used to get an Ambiq Apollo4 project up and running.

It is designed to be used with an Embedded Eclipse installation; however, all building
and flashing can be done entirely through the command line without the need for
the Eclipse IDE. The use of Eclipse when debugging is highly recommended, however, as
this project will enable you to automatically flash the device, set breakpoints, step
through running code, etc without having to deal with the multiple underlying
SEGGER and gdb interactions necessary to do this manually.

For simple flashing of production-ready code, the command line is much simpler:

1. `cd` to the root directory of this project
2. Enter `make flash`

To manually flash a test binary, do the following:

1. `cd` to the `tests` directory of this project
2. Enter `make [TEST]` where `[TEST]` is any of the targets specified in `tests/Makefile`
   corresponding to a user-defined test applications (flashing of the binary is automatic).


## Prerequisites for Using Eclipse

To use this code with Eclipse, it is recommended to install the "Embedded Eclipse" variant,
along with the GNU Embedded Toolchain and SEGGER flashing tools, all of which can be
done by executing the following:

1. Download and install the latest [SEGGER JLink Software and Documentation Pack](https://www.segger.com/downloads/jlink/) for your OS.
2. Ensure that Node.js and NPM are installed on your system.
3. Use NPM to install XPM using: `npm install --global xpm@latest`
4. Use XPM to install the GNU ARM Embedded GCC xPack: `xpm install --global @xpack-dev-tools/arm-none-eabi-gcc@latest`
5. Navigate to the [Eclipse Download Page](https://www.eclipse.org/downloads/packages/) and
   download the version called "Eclipse IDE for Embedded C/C++ Developers"
6. Install Eclipse, open it, and create a new workspace for your project wherever you'd like
7. Select File -> Import -> General -> Existing Projects into Workspace
8. In "Select root directory", choose Browse -> Go to the `Apollo4StarterCode` directory -> Select Folder -> Finish
9. Right-click the newly loaded project name ("Apollo4StarterCode") in the top-left window (labeled "Project Explorer"),
   and select Import -> Run/Debug -> Launch Configurations -> Next -> Browse to the "launchConfigs" directory ->
   Put a check mark next to the directory -> Finish
10. Everything should now be configured for you to use the IDE to debug your project.


## Project Layout and Directory Structure

If you expand the "Apollo4StarterCode" folder in the "Project Explorer," you will see
all of the files and folders in the project. All source code is under `src/`, and all
tests are under `tests/`.

The `src` directory contains four subdirectories:

* `external`: Any external libraries you might need (currently FatFS and SEGGER)
* `boards`: Directory containing folders for each revision of the same hardware.
           This is used primarily to define the pinouts and hardware connections for
           a certain revision and allows us to switch between different HW layouts
           with a simple `Makefile` flag.
* `peripherals`: Contains wrappers around necessary peripherals in a black-box fashion
                such that changing to a different peripheral (such as a different
                IMU chip or flash storage device) does not affect our application code
                in any way, and only requires that we write a new peripheral wrapper
                for the updated hardware. You are responsible for writing your own
                peripheral wrapper for any new type of device you use in your application.
* `app`: The actual application code which consumes the peripheral library

The `tests` directory contains tests for the various peripherals and any other application
or unit tests that you find useful. You are free to add tests to this directory as you
need (and make sure to update the corresponding `Makefile` to build them).


## Using Eclipse to Debug

Debugging an Apollo4 board using Eclipse is quite simple:

1. Under "Project Explorer", expand `tests/Build Targets` and double-click the test application you'd like to build
2. In the upper toolbar, click on the small arrow next to the green "bug" icon, and you will see a list of launch configurations corresponding to your tests.
3. Click the test you would like to run. This will cause the test to be flashed to the board, the board will reset, start running your code, and connect to the debugger.

At this point, you should be able to see any log messages in the bottom window entitled "Console", and you should also be able to set any number of breakpoints,
step through your code, and set variable or expression watchers.
