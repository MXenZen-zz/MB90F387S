# MB90F387S-Support
Simple Demos Using Software Library Project LIBMB90385 for FFMC-16LX MB90385 Series
MB90F387S Microcontroller!

## Introduction
Fujitsu's **Jouet Bleu Starter Kit** is designed for beginners to learn about
microcomputers despite having no [common] knowledge about microcomputers nor
experienced using microcomputers. The **Starter Kit** features a 16-bit flash
microcontroller and includes application development tools such as **Softune
Workbench** and **Accemic MDE** debugger. **Softune Workbench** also includes
sample I/O register files, standard C library files, and other microcontroller-
specific files. In addition, the hardware manual contains the proper usage and
control of hardware peripherals through registers, timing and order of access or
control sequence, meaning and interpretation of data, and other supplementary
information. 

The hardware manual and the sample I/O register files alone are enough to make
various projects and several experiments that would be capable of handling all
registers and all their possible configurations. However, this would make 
development quite tedious since accessing and modifying registers are done
through registers always. Moreover, there were no built-in functions that
beginners can use immediately and conveniently to control the hardware 
peripherals in just a few lines of code, unless, you make one.

The LIBMB90385 project is the author's attempt to produce a simple software 
library for the MB90385 series microcontrollers. Though, only the MB90F387S 
was tested using it with test codes. The demos are created by transforming
all those test codes into individual workspace projects. Generally, it is
designed to have similar syntax, approach, and structure like the open-source
software libraries nowadays. It mainly consists of data, configurations, and
functions which the developer can use within the program body without a need
for the developer to define them explicitly. It is designed to assist the 
developers in creating and completing their embedded-based projects.

*The software library was made and shared in hopes that whoever seeks it shall
find it, that whoever finds it shall use it, that whoever uses it shall improve
it, and that whoever improves it shall share his/her work.*

## Usage
The repository is a workspace that requires **Softune Workbench** to modify 
codes and to build the binary programs for embedded-based projects. **Fujitsu
Flash MCU Programmer for F2MC-16LX**, **Flashly**, or **Accemic MDE** is 
required to load the binary program to the MB90385 Series microcontroller,
preferably MB90F387S. The PROJECT demo is a template using the software
library for starting new projects. The rest of the demo projects came from
this folder. 

All project settings work within the project only. They are set to work on
modules the project needs. Most of the settings are common to all projects, 
except for one. Predefined ISRs are macros defined to make use of pre-made 
ISRs which are part of the software library. They follow the format 
USE_PREDEF_TLA_ISR  where TLA is the three-letter acronym of the module. 
Just check the USE_PREDEF_TLA_ISR under *Set(up) Project*, *C Compiler* tab,
then *Define Macro* category. Uncheck USE_PREDEF_TLA_ISR if the module is
not used. The rest of the modules may do the same.

Currently, the software library does not have a full-fledged user manual.
However, it documented the usage of functions and some variables which can
even be read directly on the source codes.

## Limitation
The software library tends to execute slower than plain or straightforward
implementation. It does not guarantee to work under all circumstances or useful
under all conditions. It utilizes a lot of stack memory especially nested 
functions, a lot of data memory for external data, and a lot of processing
power that may be unnecessary or not needed. Unless the developer is 
knowledgeable, this may [all] be avoided or minimized by having a good
software plan, design, and development.

The demos are mere examples which are not intended to guarantee the
device to fulfill its task under all circumstances. The author/developer will
not assume responsibility for damages that might be incurred by the device 
resulting from the use of the sample programs.


## External Links

[Full Workspace for Demos and Samples.](https://svn.riouxsvn.com/project-asc/02_Software/DemoMB90385/)

[Full Workspace for Library Creation.](https://svn.riouxsvn.com/project-asc/02_Software/LibMB90385/)

Developed by [Xeno Xerxes Masong](mailto:xxmasong@gmail.com).
