#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI 11 //D1
#define OLED_CLK 12//D0
#define OLED_DC 9//DC
#define OLED_CS 8//cs
#define OLED_RESET 10//reset

#define Buttom_left 2
#define Buttom_right 13

int x = 0;

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

static const unsigned char PROGMEM Logo[] = {
0x00,0x20,0x0e,0x00,
  0x00,0xf8,0x1f,0x00,
  0x01,0xf8,0x3f,0x80,
  0x01,0xfd,0x3f,0x80,
  0x01,0xfd,0xbf,0x80,
  0x01,0xf8,0x1f,0x80,
  0x00,0xf8,0x1e,0x00,
  0x00,0x10,0x08,0x00,
  0x00,0x10,0x8c,0x00,
  0x00,0x1b,0xdc,0x00,
  0x00,0x1b,0xdc,0x00,
  0x00,0x19,0xd4,0x00,
  0x00,0x10,0x00,0x00,
  0x00,0x03,0xf8,0x00,
  0x00,0x03,0xe0,0x00,
  0x00,0x00,0x80,0x00,
};

void  splash(){
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(30, 16);
  display.print("MICKEY");
}

void setup() {
  Serial.begin(9600);
  pinMode(Buttom_left, INPUT);
  pinMode(Buttom_right, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  display.drawBitmap(x, 0, Logo, 32, 16, WHITE);
  display.display();
  // put your setup code here, to run once:

}

void loop() {
  display.clearDisplay();
  if(digitalRead(Buttom_left)==1&&x>0)x--;
  else if(digitalRead(Buttom_right)==1&&x<96)x++;
  splash();
  display.drawBitmap(x, 0, Logo, 32, 16, WHITE);
  display.display();
  delay(1);
  // put your main code here, to run repeatedly:

}
