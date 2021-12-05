// This code is a basic test programme to make the 5110 LCD display work - for testing.
// Some displays are dead on arrival - so this will quickly test if it works.
// You will need to make sure you have the 2 libraries below installed. These are created by Adafruit, and can be found using built in library manager.

#include <Adafruit_GFX.h>                                 //Download / add "Adafruit_PCD8544" library using the library manager  
#include <Adafruit_PCD8544.h>                             //Download / add "Adafruit_PCD8544" library using the library manager  



boolean backlight = true;                                 // enables the backlight 
int contrast=60;                                          // sets contrast - adjust if display too light / dark,  higher number is darker
#define BacklightPin 10                                   // PWM pin to use for backlight. (any PWM supporting pin is fine)
int BacklightVal = 160;                                   // This is the PWM value for the backlight LED brightness. 


Adafruit_PCD8544 display = Adafruit_PCD8544( 5, 4, 3);    // we can configure the pins to use on the uC for data communication to the display



unsigned long timer = 0;

/* Module Pin layout / numbers may vary depending on module version. Double check your pins. 
 * NOKIA Screen   [xxxTopxxx]
 *                [         ]
 *                [12345678 ]
 *  eg  DisplayPinNo. > UnoPinNo.    RST.1>uno.3, CE.2>uno.4, DC.3>d5 , DIN.4>d11, CLK.5>d13, VCC.6>uno.3v3, LIGHT.7>pwm10, GND.8 > unoGND 
 *
 */




void setup() {                                /// Code here is run once during startup

analogWrite(BacklightPin, BacklightVal); 

display.begin();    
display.setContrast(contrast);  
display.clearDisplay(); 
display.display();   
display.setTextSize(1);
display.clearDisplay();
display.setTextColor(BLACK, WHITE);
display.setCursor(6,0);
display.print("Screen Test");
display.display();
delay(1000);
}


void loop() {                           /// Code here is looped forever
  analogWrite(10, BacklightVal);
  display.setCursor(16,10);
  timer = millis();
  display.print(timer);
  display.display();
  delay(25);
  
}
