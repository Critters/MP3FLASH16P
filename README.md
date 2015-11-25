# MP3FLASH16P
An Arduino library I created for the incredibly cheap MP3 Voice Module. It gives you simple commands to play and stop numbered MP3 or WAV files as well as setting the volume and knowing if a file is still playing.

You can find several of these modules on eBay by searching for "MP3 FLASH 16P", they should be around $4.99. I purchased this one:
http://www.ebay.com/itm/BY8301-16P-SSOP2-MP3-Aduio-Serial-Voice-SPI-FLASH-Module-3W-Amplifier-Micro-USB-/271684522808?hash=item3f41a8d338:g:KXMAAOSw7ThUdS08

# Background
This is my first Aruino library, you've been warned :)

I made it as I found very little information on using this module with Arduino, what code is included in the PDF is for a different controller and isn't very user friendly. My goal with this library is to give you stupid-simple commands to play named files so you can add some nice sounds to your project without breaking the bank on modules that are well documented but cost 4 to 5x as much.

# Install
Copy the MP3FLASH16P folder into your Arduino/libraries folder and restart the Arduino IDE if it's already running

# In the "Support Files" folder
* The device has no pins labeled on the PCB so I've included a PNG of the pins to help you out
* Most of the links to the manual on the pages of the eBay sellers 404, I found one place that still had it cached so that file is also included. I could only find it in Chinese so used Google Translate to figure things out
* The module comes with mp3 files pre-installed, I suspect they are counting from 1 to 10 in Chinese but don't know for sure. I've included replacement files that count from 1 to 10 in English to help with testing

# Examples
I've included two examples that show a super simple and more complex use cases, you should be able to find them under file/examples/MP3FLASH16P/ in your Arduino IDE