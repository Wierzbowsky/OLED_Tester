//
// OLED Screen Tester Firmware. v1.0
//
// Created by Wierzbowsky [RBSC] for testing OLED screens for Gotek
// Public domain, use in any of your projects freely
//

#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define I2C_ADDRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

//Adafruit_SSD1306 display(OLED_RESET);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SDA         18    //  Arduino A4 > screen SDA
#define SCL         19    //  Arduino A5 > screen SCL
#define NLED        13    //  Arduino D13 > NanoLED

// Subroutines

void ClearScreen()
{
  display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_BLACK);
  display.display();
}

void ClearScreenW()
{
  display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
  display.display();
}

// Startup code

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ; /* wait */

  digitalWrite(NLED, 1); // Nano led on

  display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS);
  display.clearDisplay();
  display.setTextSize(1);
  display.cp437(true);
  display.setTextColor(SSD1306_WHITE);

  Serial.println();
  Serial.println("OLED TESTER v1.0 by Wierzbowsky [RBSC]");
  Serial.println("Starting up...");

  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
  display.setCursor(4,4);
  display.println(" OLED SCREEN TESTER");
  display.setCursor(4,13);
  display.println("   Version 1.0 by");
  display.setCursor(4,22);
  display.println(" Wierzbowsky [RBSC]");
  //display.setCursor(4,40);
  //display.println(" Test is starting.");
  display.display();

  delay(1500);
  ClearScreen();
  interrupts();
  digitalWrite(NLED, 0); // Nano led off
}

// Main code

void loop()
{
  int i;

  interrupts();

  Serial.println("Test is starting...");
  Serial.flush();

  // Full screen fill
  Serial.println("Full screen test. Watch the screen...");
  Serial.flush();

  ClearScreen();
  for (i = 9; i > 0; i--)
  {
    ClearScreen();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 13);
    display.println(i);
    display.display();
    digitalWrite(NLED, 1); // Nano led on
    delay(500);
    ClearScreenW();
    digitalWrite(NLED, 0); // Nano led off
    delay(500);
  }
  ClearScreen();
  delay(500);

  // Screen frame test
  Serial.println("Screen frame test. Watch the screen...");
  Serial.flush();

  ClearScreen();
  for (i = 9; i > 0; i--)
  {
    ClearScreen();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 13);
    display.println(i);
    display.display();
    digitalWrite(NLED, 1); // Nano led on
    delay(500);
    display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    digitalWrite(NLED, 0); // Nano led off
    delay(500);
  }
  ClearScreen();
  delay(500);

  // Strobe test
  Serial.println("Strobe test. Watch the screen...");
  Serial.flush();

  ClearScreen();
  for (i = 100; i > 0; i--)
  {
    ClearScreen();
    ClearScreenW();
  }
  ClearScreen();
  digitalWrite(NLED, 0); // Nano led off
  delay(500);

  // Wireframe fill test
  Serial.println("Wireframe test. Watch the screen...");
  Serial.flush();

  digitalWrite(NLED, 1); // Nano led on
  ClearScreen();
  for (i = 0; i < SCREEN_HEIGHT; i = i + 6)
  {
    display.drawLine(0, i, SCREEN_WIDTH, i, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i = i + 15)
  {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(1000);  
  ClearScreen();
  delay(500);

  ClearScreen();
  for (i = 0; i < SCREEN_HEIGHT; i = i + 4)
  {
    display.drawLine(0, i, SCREEN_WIDTH, i, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i = i + 9)
  {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(1000);  
  ClearScreen();
  delay(500);

  ClearScreen();
  for (i = 0; i < SCREEN_HEIGHT; i = i + 2)
  {
    display.drawLine(0, i, SCREEN_WIDTH, i, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i = i + 5)
  {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(1000);  
  ClearScreen();
  digitalWrite(NLED, 0); // Nano led off
  delay(500);

  // Inverse wireframe fill test
  Serial.println("Inverse wireframe test. Watch the screen...");
  Serial.flush();

  digitalWrite(NLED, 1); // Nano led on
  ClearScreenW();
  for (i = 0; i < SCREEN_HEIGHT; i = i + 6)
  {
    display.drawLine(0, i, SCREEN_WIDTH, i, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i = i + 15)
  {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(1000);  
  ClearScreenW();
  delay(500);

  ClearScreenW();
  for (i = 0; i < SCREEN_HEIGHT; i = i + 4)
  {
    display.drawLine(0, i, SCREEN_WIDTH, i, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i = i + 9)
  {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(1000);  
  ClearScreenW();
  delay(500);

  ClearScreenW();
  for (i = 0; i < SCREEN_HEIGHT; i = i + 2)
  {
    display.drawLine(0, i, SCREEN_WIDTH, i, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i = i + 5)
  {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(1000);  
  ClearScreen();
  digitalWrite(NLED, 0); // Nano led off
  delay(500);

  // Rect fill test
  Serial.println("Filled rectangle test. Watch the screen...");
  Serial.flush();

  digitalWrite(NLED, 1); // Nano led on
  ClearScreen();
  for (i = 0; i < SCREEN_HEIGHT; i++)
  {
    display.fillRect(0, i, SCREEN_WIDTH, i, SSD1306_WHITE);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = SCREEN_HEIGHT; i > 0; i--)
  {
    display.fillRect(0, i, SCREEN_WIDTH, i, SSD1306_BLACK);
    display.display();
    delay(100);
  }
  delay(500);
  for (i = 0; i < SCREEN_WIDTH; i++)
  {
    display.fillRect(i, 0, i, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(50);
  }
  delay(500);  
  for (i = SCREEN_WIDTH; i > 0; i--)
  {
    display.fillRect(i, 0, i, SCREEN_HEIGHT, SSD1306_BLACK);
    display.display();
    delay(50);
  }
  digitalWrite(NLED, 0); // Nano led off
  delay(500);

  // Text display test
  Serial.println("Text display test. Watch the screen...");
  Serial.flush();

  digitalWrite(NLED, 1); // Nano led on
  ClearScreen();
  for (i = 0; i < SCREEN_WIDTH; i++)
  {
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(i, 8);
    display.println("TEST TEST TEST TEST");
    display.display();
    delay(50);
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(i, 8);
    display.println("TEST TEST TEST TEST");
    display.display();
  }
  delay(500);
  ClearScreenW();
  for (i = 0; i < SCREEN_WIDTH; i++)
  {
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(i, 8);
    display.println("TEST TEST TEST TEST");
    display.display();
    delay(50);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(i, 8);
    display.println("TEST TEST TEST TEST");
    display.display();
  }
  delay(500);
  ClearScreen();
  for (i = 0; i < SCREEN_HEIGHT; i++)
  {
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(7, i);
    display.println("TEST TEST TEST TEST");
    display.display();
    delay(25);
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(7, i);
    display.println("TEST TEST TEST TEST");
    display.display();
  }
  delay(500);
  ClearScreenW();
  for (i = 0; i < SCREEN_HEIGHT; i++)
  {
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(7, i);
    display.println("TEST TEST TEST TEST");
    display.display();
    delay(25);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(7, i);
    display.println("TEST TEST TEST TEST");
    display.display();
  }
  digitalWrite(NLED, 0); // Nano led off
  ClearScreen();
  delay(1000);
  
  ClearScreenW();
  display.setTextColor(SSD1306_BLACK);
  display.setCursor(4,4);
  display.println(" OLED SCREEN TESTER");
  display.setCursor(4,13);
  display.println("   Version 1.0 by");
  display.setCursor(4,22);
  display.println(" Wierzbowsky [RBSC]");
  //display.setCursor(4,40);
  //display.println(" Test is finished!");
  display.display();

  Serial.println("Test is finished. It will be restarted in 10 seconds...");
  Serial.flush();

  delay(10000);
}
