# Flair 58 EVA Project

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="/img/logo.png">
  <img alt="Shows an illustrated sun in light color mode and a moon with stars in dark color mode." src="/img/logo_light.png">
</picture>




**The (long term) plan:** ESP32-Hosted webserver, serving machine controls to any device (laptop, phone, tablet) to control the actuators and enable automated pressure profiling. 

Off the Shelf Hardware: 
- ESP32: [Amazon](a.co/d/gceXPfS)
    - Working so far. 👍 I'm inclined to think any variety should work. The "narrow" version is nice because it fits in a standard breadboard with 1 column available on either side. 
- Linear Actuators: [RobotDigg](https://robotdigg.com/product/1815/9-36VDC-stepper-motor-gear-drive-linear-actuator)
    - Two are needed to achieve the pressure and maintain actuator speed consistent with 9bar/30sec shot profiles.
    - 100mm stroke length used (required?) for this design. 
    - *Please make a PR to this readme if you believe you have alternative options.*
- TMC2209 Driver: [Amazon](https://www.amazon.com/dp/B08DFV4QQ1?psc=1&ref=ppx_yo2ov_dt_b_product_details)
    - Working so far. 👍 No configuration or anything set up, just tested basic communication. Initial test can be seen [here](https://github.com/johnrbell/ESP32_TCM2209_Testing).
    - These specific ones have misprints on the silkscreening which is noted in the [fysetc wiki](https://wiki.fysetc.com/Silent2209/#v30-hardware-connection). 🤨 
- 24v to 5v Converter:  [Amazon](https://www.amazon.com/dp/B08NZV88MC?psc=1&ref=ppx_yo2ov_dt_b_product_details)
    - To power the ESP32 from the PSU if not using another source. Using USB for the forseeable future. 
- 150w 24v PSU:  [Amazon](https://www.amazon.com/dp/B077B7DHYL?psc=1&ref=ppx_yo2ov_dt_b_product_details)
    - Provides 24v to drive the steppers/actuators. 

Custom Hardware:
- Custom lever hinges.
    - Currently 3D Printed for testing purposes. 
- Custom lever hinge pins. 
    - TBD.


All in, off the shelf parts should be about $150. A significant portion of that is shipping actuators from China at about $45.

The custom hardware is estimated between $20 and $50 depending on process and finish. 

## Pinouts:

ESP32 WROOM 32D V4:
![image](/img/esp32_pinout.png)
Image belongs to [Espressif](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html).
<!-- TMC2209 Stepper Driver - ![image](/img/tmc2209_pinout.png) -->

## Environment Setup
I'll steal something from Perl here: **TIMTOWTDI**: There's more than one way to do it.

In my case i used [VS Code](https://code.visualstudio.com/) & the [Platform.io](https://platformio.org/) extension. 

You'll also need the [USB to UART Bridge VCP Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)

## "Includes"
You'll need a file named: `wifi_creds.h` in your `/src` dir. 

It should be in the following format: 

```C++
const char *WIFI_SSID = "thatsWhatSheSSID";
const char *WIFI_PASS = "sprinkles";
```

## Disclaimer
If I knew what I was doing, I'd be done. 

I'm learning as I go. Don't burn your kitchen down. 🔥
<!-- ## Contributors: -->