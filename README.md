# cmd-c-serialport

serialsimple, aplicacion para aprender usar el RS-232 simple library

## introduction

try to use a single header/source to send and receive msg to the serial printers, 
byt the implementation of the Library/source RS-232

## Status

It uses polling to receive characters from the serial port.
Interrupt/event-based is not supported.

Original base code are RS-232 from Teunis van Beelen ( http://www.teuniz.net/RS-232/)

## instructions

Compiling the demo's can be done as follows:

`gcc demo_rx.c rs232.c -Wall -Wextra -o2 -o test_rx`

`gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx`

or use the `Makefile` by entering `make`

Run the demo by typing:

`./test_rx`

or

`./test_tx`

On w32/w64 must use  Mingw for compilation.


## USage/implementation

To include this library into your project:

Put the two files `rs232.h` and `rs232.c` in your project/sourcedirectory.

Write `#include "rs232.h"` in your sourcefiles that needs access to the library/source impelemntation.

Add the file `rs232.c` to your project settings (in order to get it compiled and linked with your program).


