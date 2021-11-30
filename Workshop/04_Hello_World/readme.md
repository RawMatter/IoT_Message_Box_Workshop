# Hello World
Even 5 years ago connecting any embedded device to the internet required at least 3 days of aimlessly staring at compiler errors and a blood saccrifice. Today we're going to do it with less than 12 lines of code and we could probably do it in 2 if we completely ignored any sense of style.

<p align="center" style="margin-top:30px; margin-bottom:30px">
<img src="https://media.giphy.com/media/xUNda2iBiYqk4mKDRu/giphy.gif" width="300px"></p>

# WiFi Library
The arduino framework has a number of native libraries that dont require any support from platformIO. One of these is the WiFi library. Lets include it now, and another sneaky file too...

```cpp
// Add the WiFi library and our secrets definition
#include <WiFi.h>
#include "secrets.h"
```

## Its a secret
To manage our code and ensure we dont commit secret information to public repositories its a good idea to store this sensitive information in another file. By listing this secrets file in our `.gitignore` file we can protect ourselves from potentially expensive attacks.

Arguably WiFi credentials are not that important, but we will want to protect our AWS keys as well later!

So create a new file in your `src` folder called `secrets.h`. Inside the file we need to store our WiFi crendentials
```cpp
const char* SSID = "honeypot";
const char* PASSWORD = "1337Hax0rZ";
```

Dont forget to include it in your `main.c` file either
```cpp
// WiFi Parameters are define in the "secrets" header file
#include "secrets.h"
```

Lets also add this file name into our `.gitignore` file
```
secrets.h
```

# Connecting to WiFi
Now the serious business of connecting to the internet....

```cpp
// Initialise the WiFi library with network parameters  
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
```
Thats it! Those few lines of code inside your `setup()` routine are all it takes to connect to the rest of the world.

p align="center" style="margin-top:30px; margin-bottom:30px">
<img src="https://media.giphy.com/media/1aejdvBiVkJsk/giphy.gif" width="400px"></p>

# MAC Daddy

Our WiFi library provides access to other useful information:
* MAC address
* IP
* Channel
* Probably a few other too...

Having access to this information and displaying it to a user without the need to connect a serial port can be very useful. Try replacing your `loop` code with this code instead

```cpp
void loop() {
  // Simple multi line string formatting
  Serial.print("loop ");
  Serial.println(counter);
  
  tft.fillScreen(TFT_BLUE);
  tft.setCursor(5, 0, 2);
  tft.setTextSize(2);
  tft.print("IP: ");
  tft.println(WiFi.localIP());
  tft.print("Channel: ");
  tft.println(WiFi.channel());
  tft.setTextSize(2);
  tft.println("MAC: ");
  tft.print(WiFi.macAddress());


  sleep(1);
}
```

As exciting as network information may be, it doesn't really have that wow factor we're chasing. In the next phase, things are going to get a little cloudy!

<p align="center" style="margin-top:30px; margin-bottom:30px">
<img src="https://media.giphy.com/media/l1J9JrxgSYFB1mqYg/giphy.gif"></p>