/*********************************************************************
  This is an example for our Monochrome OLEDs based on SH110X drivers

  This example is for a 128x64 size display using I2C to communicate
  3 pins are required to interface (2 I2C and one reset)

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada  for Adafruit Industries.
  BSD license, check license.txt for more information
  All text above, and the splash screen must be included in any redistribution

  i2c SH1106 modified by Rupert Hirst  12/09/21
*********************************************************************/



#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup()   {

  // Initialize the display without showing the Adafruit logo
  if (!display.begin(0x3C)) {  // Address 0x3C for SH1106
    Serial.println("SH1106 allocation failed");
    for (;;);  // Don't proceed, loop forever
  }
  
  display.clearDisplay();   // Clear any pre-drawn content (e.g., logo)
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.

  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
 //display.setContrast (0); // dim display
 
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  // Set text color to white
  display.setTextColor(SH110X_WHITE);

}


void loop() {
  // Set text size, cursor, and display message
  display.setTextSize(1);   // Larger font size for next message
  display.setCursor(0, 1); // Adjust the position for larger text
  display.println("eavesdropper.dev");
  display.setCursor(0, 20); // Adjust the position for larger text
  display.println("In the shadows,");
  display.println("we build.");
  display.display();  // Send buffer to the display

  for (int i = 0; i < 120; i++) {
      display.setCursor(i, 40); // Adjust the position for larger text
      display.print(".");
      delay(5);
      display.display();  // Send buffer to the display

  }
  display.clearDisplay();

}






