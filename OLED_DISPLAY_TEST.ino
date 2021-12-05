// This is a basic test code for I2C type OLED displays
// I2C devices use 2 data pins, SDA & SCL.  Connect SDA > SDA or A4 on uC & SCL > SCL or A5.
// SPI type displays use at least 4 data pins. SCK, MOSI, MISO and CS. This code does not support SPI versions. 

#include <Adafruit_GFX.h>                               // Ensure you have both libraries installed. 
#include <Adafruit_SSD1306.h>                           // 

#define Pixels_Wide 128                                 // both common displays are 128 pixels wide
#define Pixels_High 64                                  // some displays are 32 pixels, some 64 pixels, change as required
#define Oled_Address 0x3C                               // Some displays have different addresses. try  0x3D or 0x3C 

int aTimer = 0;
int aCounter = 0;

// If your display doesn't seem to work with either address, Try finding a "I2C address scanner" code, that will print it on console.

Adafruit_SSD1306 display(Pixels_Wide, Pixels_High);    // send the width and hight values to the SSD1306 library.



void setup() {
 
display.begin(SSD1306_SWITCHCAPVCC, Oled_Address);
display.clearDisplay();
display.setTextColor(SSD1306_WHITE); 
display.setTextSize(1); 
display.setCursor(0,0);   
display.println(F("OLED Test Code"));
display.display();
delay(2000); 
display.clearDisplay();
 
}

void loop() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

aTimer = millis();
aCounter++; 

  display.setTextSize(1);             // font size 1
  display.setCursor(0,0);             // (across,down)
  display.print(("timer = "));
  display.print(aTimer);

  display.setTextSize(2);             // font size 1
  display.setCursor(0,10);  
  display.print(("C = "));
  display.print(aCounter);


  display.setTextSize(1); 
  display.setCursor(0,30); 
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Invert the colour
  display.print("Inverted");

  display.setTextSize(3); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20,40); 
  display.print("...3");

  display.display();
  delay(250);
}
