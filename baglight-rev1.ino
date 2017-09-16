
#include <Adafruit_NeoPixel.h>
#define PIN 4
// pin 9 for first switch wired between 5v and pin9 with 10k resistor between pin and ground
#define inPin 9
//pin 10 for second switch wired between 5v and pin9 with 10k resistor between pin and ground
#define inPin1 10

// 3 8led neopixel sticks wired to pin 6 for baglight or helmet light

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(24, PIN);
int dly = 200;
uint32_t color[8] = {0xFF0000, 0xff7f00, 0xffff00, 0x87f717, 0x00ff00, 0x0000ff, 0x4b0082, 0x8f0099,};
uint8_t a,b,c;
int val;
int valn;
int val1n;
int lightstate = 0;

void setup() {
  pinMode(inPin, INPUT); // first(mode) switch setup
  pinMode(inPin1, INPUT); // second(bright) switch setup
  val = digitalRead(inPin); // read mode switch to set base value
  pixel.begin();
  pixel.setBrightness(85); // 1/3 brightness
}

void loop() {
  // put your main code here, to run repeatedly:
valn = digitalRead(inPin); // read mode switch to see if it has changed
val1n = digitalRead(inPin1); // read bright switch
delay(50);
//set brightness to match state of bright switch
if (val1n == 0){
pixel.setBrightness(85);  
}
else {
pixel.setBrightness(255);  
}
// if mode switch has changed go to next light state and change animation of lights.  
if (valn != val){
val = valn;
lightstate = lightstate +1;
if(lightstate > 6){
  lightstate = 0;
}
}
//white blink
  if (lightstate == 0) 
     {
     for (b=0; b<24; b++){
     pixel.setPixelColor(b, 0xffffff);
     }
     pixel.show();
     delay(dly/2);
     for (b=0; b<24; b++){
     pixel.setPixelColor(b, 0x000000);
     }
     pixel.show();
     delay(dly/2); 
     }
  // lantern mode
  if (lightstate == 1) 
     {
     for (b=0; b<24; b++){
     pixel.setPixelColor(b, 0xffffff);
     }
     pixel.show();
     delay(dly);
     }     
  //red blink
  if (lightstate == 2) {
     for (b=0; b<24; b++){
     pixel.setPixelColor(b, 0xffffff);
     }
     pixel.show();
     delay(dly);
     for (b=0; b<24; b++){
     pixel.setPixelColor(b, 0xff0000);
     }
     pixel.show();
     delay(dly); }
   //White left right blink
   if (lightstate == 3) {
     for (b=0; b<12; b++){
     pixel.setPixelColor(b, 0xffffff);
     pixel.setPixelColor(b+12,0xff0000);
     }
     pixel.show();
     delay(dly);
     for (b=0; b<12; b++){
     pixel.setPixelColor(b, 0xff0000);
     pixel.setPixelColor(b+12, 0xffffff);
     }
     pixel.show();
     delay(dly); }

  //red-white multi blink
  if (lightstate == 4) 
  {
     for (b=0; b<4; b++){
     pixel.setPixelColor(b, 0xffffff);
     pixel.setPixelColor(b+4, 0xff0000);
     pixel.setPixelColor(b+8, 0xffffff);
     pixel.setPixelColor(b+12, 0xff0000);
     pixel.setPixelColor(b+16, 0xffffff);
     pixel.setPixelColor(b+20, 0xff0000);
     }
     pixel.show();
     delay(dly);
     for (b=0; b<4; b++){
     pixel.setPixelColor(b, 0xff0000);
     pixel.setPixelColor(b+4, 0xffffff);
     pixel.setPixelColor(b+8, 0xff0000);
     pixel.setPixelColor(b+12, 0xffffff);
     pixel.setPixelColor(b+16, 0xff0000);
     pixel.setPixelColor(b+20, 0xffffff);
     }
     pixel.show();
     delay(dly);
  }
// cylon eyes
  if (lightstate == 5)
  {
         for (b=0; b<21; b++){
     for (a=0; a<24; a++){
     pixel.setPixelColor(a,0xffffff);
     }
     pixel.setPixelColor(b,0xff0000);
     pixel.setPixelColor(b+1,0xff0000);
     pixel.setPixelColor(b+2,0xff0000);
     pixel.setPixelColor(b+3,0xff0000);
     pixel.show();
     delay(dly/4);
     }
     delay(dly/4);
     for (b=19; b>0; b--){
     for (a=0; a<24; a++){
     pixel.setPixelColor(a,0xffffff);
     }
     pixel.setPixelColor(b,0xff0000);
     pixel.setPixelColor(b+1,0xff0000);
     pixel.setPixelColor(b+2,0xff0000);
     pixel.setPixelColor(b+3,0xff0000);
     pixel.show();
     delay(dly/4);   
     } 
  //delay(dly/4);
  }
   // rainbow
  if (lightstate == 6) {
   for (a=0; a<8; a++){
   for (b=0; b<24; b=b+3){
   if ((b/3)-a >= 0)
   {
     c=(b/3)-a;
     pixel.setPixelColor(b,color[c]);
     pixel.setPixelColor(b+1,color[c]);
     pixel.setPixelColor(b+2,color[c]);
   }
   else 
   {
     c=8-(a-(b/3));
     pixel.setPixelColor(b,color[c]);
     pixel.setPixelColor(b+1,color[c]);
     pixel.setPixelColor(b+2,color[c]);
   }
  }
  pixel.show();
  delay (dly);
   }
  } 
 } 
 
