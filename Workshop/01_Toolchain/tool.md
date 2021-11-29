# Tools

To program it we need to configure a *toolchain*, this is all of the utilities, libraries and drivers required to compile a program and write it to the flash memory of the device and have it execute on boot

## Toolchain
Microcontroller projects, like much of computer science have never been more accessible and this is thanks to the open source community. 

Arduino kicked this off in a big way back in the early 2000's their big innovation was abstracting the complexity of registers and creating a bootloader that made it easy to upload code via a serial port
For those who dabbled, their IDE was a strange Java headache that still gives me night terrors

Today, we are going to be doing all of our work inside VSCode, its catching on as an IDE....
We're going to be using a fairly chunky native plugin called Platform IO

This simplifies a whole bunch of things:
* All the managers:
    * Common boards
    * Libraries 
    * Platforms
        * Arduino
        * ESP-IDF
        * Teensy
        * etc...
* Handles all of the platform debendancies and sandboxes things nicely
* Simple access to build and monitor tools
* Debugging integration
* Devops stuff:
    * Unit tests
    * Remote development
    * Continuous Integration

Not limited to VSCode, you can also use it with Cloud9, Atom (where it started), Eclipse

The main reason we are using it today is for the managers, a few lines of code and our project is configured. It also plays well cross platform (I believe, *viva la Windows*)

# Install all the things
### *VSCode*

If you are not already a VSCode convert, today you are.

1. Install VSCode from [here](https://code.visualstudio.com/) and follow the prompts

### *PlatformIO*
1. Launch VSCode 
2. Open the extension manager with the icon or `[ctrl] + [shift] + [p]` on windows
3. Search for `platformio ide` 
4. Tricky step.... install the extension




