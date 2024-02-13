#include <Adafruit_NeoPixel.h>
#define echopin 7
#define trigpin 8
long duration;
float distance;

#define PIN 5
#define NUMPIXELS 24 // total number of neopixels


Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
//to tell the arduino how many pixels are there and which digital pin is connected to send signals.

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(115200);
  pixels.begin(); //to initialize the neopixel strip
}

void loop() 
{
  pixels.clear(); //to set all pixel colours off
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("cm");
  //Setting is 315 cm because the distance between
  //the ultrasonic sensor and the next wall is 202cm and thus if any person
  //comes in between them then the ultrasonic sensor might record it.
  if(distance<315.0)
  {
    for(int i=0; i<NUMPIXELS; i++) 
    { 
    	pixels.setPixelColor(i, pixels.Color(0, 150, 0));//iT GIVES A LIGHT GREEN COLOR TO THE PIXELS
    	pixels.show();   // Send the updated pixel colors to the hardware.
    	//delay(500); // Pause before next pass through loop
    }
  }
  else if(distance>=315.0)
  {
    for(int i=0; i<NUMPIXELS; i++) 
    { 
    	pixels.setPixelColor(i, pixels.Color(0, 0, 0));//iT GIVES A off TO THE PIXELS
    	pixels.show();   // Send the updated pixel colors to the hardware.
    	//delay(500); // Pause before next pass through loop
    }
  }
    
    
  	
}