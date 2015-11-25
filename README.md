# MP3FLASH16P
An Arduino library I created for the incredibly cheap MP3 Voice Module. It gives you simple commands to play and stop numbered MP3 or WAV files. You can also adjust the volume and query if a file is still playing.

You can find several of these modules on eBay by searching for "MP3 FLASH 16P", they should be around $4.99. I purchased this one:
http://www.ebay.com/itm/BY8301-16P-SSOP2-MP3-Aduio-Serial-Voice-SPI-FLASH-Module-3W-Amplifier-Micro-USB-/271684522808?hash=item3f41a8d338:g:KXMAAOSw7ThUdS08

# Background
This is my first Aruino library, you've been warned :)

I made it as I found very little information on using this module with Arduino, what code is included in the Chinese-only documentation is for a different controller and isn't very user friendly. My goal with this library is to give you stupid-simple commands to play named files so you can add some nice sounds to your project without breaking the bank on modules that are well documented but cost 4 to 5x as much.

# Install
Copy the MP3FLASH16P folder into your Arduino/libraries folder and restart the Arduino IDE if it's already running
The library assumes RX/TX are on pins 10/11. To change this edit the .ccp file.

# In the "Support Files" folder
* The device has no pins labeled on the PCB so I've included a PNG of the pins to help you out
* Most of the links to the manual on the pages of the eBay sellers 404, I found one place that still had it cached so that file is also included. I could only find it in Chinese so used Google Translate to figure things out
* The module comes with mp3 files pre-installed, I suspect they are counting from 1 to 10 in Chinese but don't know for sure. I've included replacement files that count from 1 to 10 in English to help with testing

# Examples
I've included two examples that show a super simple and more complex use cases, you should be able to find them under file/examples/MP3FLASH16P/ in your Arduino IDE

# Commands
* void init(int PIN_BUSY, int VOLUME [OPTIONAL]);
Call this in Setup()
The PIN_BUSY should be whichever Arduino pin is tied to the "BUSY" pin on the device, see the pin layout PNG in the support files. 
Volume is optional and defaults to 100%, the range is 0 to 30.

* void playFile(int FILE_NUMBER, int VOLUME [OPTIONAL]);
Plays the file number you pass along with optional volume. This plays the file right away and stops anything currently playing to do so. This lets you continue to execute your Arduino code while the sound is playing

* void playFileAndWait(int FILE_NUMBER, int VOLUME [OPTIONAL]);
Same as playFile() but pauses the Arduino code until the playback is completed

* void setVolume(int VOLUME);
Sets the volume, any change you make only impacts the next time you playFile() or playFileAndWait(), you can't change the volume of a file already playing

* void volumeUp();
Increases the volume by ~15%

* void volumeDown();
Decreases the volume by ~15%

* void stopPlay();
Stops the playback

* bool isBusy();
Returns TRUE if a file is playing, note that it can take around 100ms for a file to start playing after calling playFile(), so don't test this right away