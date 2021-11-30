# Tools

To program a micro we need to configure a *"toolchain"*. This is a collective term for all of the utilities, libraries and drivers required to compile a program and write it to the flash memory of the device.

### Terminology
This workshop uses a number of terms interchangably:
* micro 
* micro-controller
* micro controller
* MCU
* embeded device
* SOC
* Widget
* Thingamajig

If in doubt, its almost certainly a reference to the $20 modern marvel attached to your laptop right now

# Toolchain
Microcontroller projects, like much of computer science have never been more accessible and this is thanks to the open source community. 

Arduino kicked this off in a big way back in the early 2000's their  innovation was abstracting the complexity of registers and creating a bootloader that made it easy to upload code via a serial port.
For those who dabbled, their IDE was a strange Java headache that still gives me night terrors

Today, we are going to be doing all of our work using VSCode, its catching on as an IDE.... 

Platform IO is a native extension for VSCode and this simplifies some teedious parts of developing software for micros:
* It has all the managers:
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
5. Wait..


# Big Sur is a big headache
Driver problems with hardware are unfortunately not uncommon, This should hopefully get you back on track!

Big thanks to Colby!

Install Drivers:
https://github.com/WCHSoftGroup/ch34xser_macos

In the terminal identify the port with

```bash
ls /dev | grep tty.wch
```

Should see something like....
```
tty.wchusbserial1234567
```

Update your `platformio.ini` file with a specified port
```
upload_port = /dev/tty.wchusbserial1234567
monitor_port = /dev/tty.wchusbserial1234567
```
<p align="center" style="margin-top:60px">
<img src="https://media.giphy.com/media/3y0oCOkdKKRi0/giphy.gif"/>
</p>

