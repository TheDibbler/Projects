Installing Additional Arduino Libraries
----------------------------------------
Once you are comfortable with the Arduino software and using the
built-in functions, you may want to extend the ability of your Arduino
with additional libraries.

What are Libraries?
----------------------------------------
Libraries are a collection of code that makes it easy for you to connect 
to a sensor, display, module, etc. For example, the built-in 
LiquidCrystal library makes it easy to talk to character LCD displays. 
There are hundreds of additional libraries available on the Internet for 
download. The built-in libraries and some of these additional libraries
are listed here: http://arduino.cc/en/Reference/Libraries. To use the
additional libraries, you will need to install them.

How to Install a Library
----------------------------------------
Libraries are often distributed as a ZIP file or folder. The name of the 
folder is the name of the library. Inside the folder will be a .cpp 
file, a .h file and often a keywords.txt file, examples folder, and other
files required by the library.

To install the library, first quit the Arduino application.

Then uncompress the ZIP file containing the library.  For example, if
you're installing a library called "ArduinoParty", uncompress
ArduinoParty.zip.  It should contain a folder called ArduinoParty, with
files like ArduinoParty.cpp and ArduinoParty.h inside.  (If the .cpp and
.h files aren't in a folder, you'll need to create one.  In this case,
you'd make a folder called "ArduinoParty" and move into it all the files
that were in the ZIP file, like ArduinoParty.cpp and ArduinoParty.h.)  

Drag the ArduinoParty folder into this folder (your libraries folder).
Under Windows, it will likely be called "My Documents\Arduino\libraries".
For Mac users, it will likely be called "Documents/Arduino/libraries".
On Linux, it will be the "libraries" folder in your sketchbook.

Your Arduino library folder should now look like this (on Windows):
  My Documents\Arduino\libraries\ArduinoParty\ArduinoParty.cpp
  My Documents\Arduino\libraries\ArduinoParty\ArduinoParty.h
  My Documents\Arduino\libraries\ArduinoParty\examples
  ....
or like this (on Mac):
  Documents/Arduino/libraries/ArduinoParty/ArduinoParty.cpp
  Documents/Arduino/libraries/ArduinoParty/ArduinoParty.h
  Documents/Arduino/libraries/ArduinoParty/examples
  ...
or similarly for Linux.

There may be more files than just the .cpp and .h files, just make sure 
they're all there.

(The library won't work if you put the .cpp and .h files directly into
the libraries folder or if they're nested in an extra folder.  For 
example:
  Documents\Arduino\libraries\ArduinoParty.cpp and
  Documents\Arduino\libraries\ArduinoParty\ArduinoParty\ArduinoParty.cpp
won't work.)

Restart the Arduino application. Make sure the new library appears in the 
Sketch->Import Library menu item of the software.

That's it! You've installed a library!
