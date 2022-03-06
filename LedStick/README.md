## LedStick
<!-- small talk-->
One of the most used projects is "LedStick", which is usually made from:
* led-stripe
* profile for led-stripe 
* led-controller.

So I didn't miss it either and here is it. I just bought a led-stipe with a profile, then I printed a [stand](https://github.com/alex-waage/SmartHome26/blob/main/LedStick/Stand/LedStick%20-%20stand.stl) for that and to control the led-stripe I'm using [Sonoff WiFi Controller](https://www.chytrevypinace.cz/Sonoff-L2-C-d239.htm). But something happened.

<!-- interesting thing about sonoff -->
You can easily connect many sonoff devices to the Home Assistant, but you can't connect this controller for no reason to HA. So I decided to flash the firmware into [Tasmota](https://github.com/arendst/Tasmota) and then connect the driver to Home Assistant, because that's what this is about.
<!-- obrázek-->
![LedStick](https://github.com/alex-waage/SmartHome26/blob/main/LedStick/Photo/2.jpg)
