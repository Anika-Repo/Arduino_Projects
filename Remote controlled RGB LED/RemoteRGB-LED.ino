#include <IRremote.h>
#define USE_IRREMOTE_AS_PLAIN_INCLUDE

const int Reciever = 2;      
const int red= 11; 
const int green= 6;
const int blue = 10;
//saving pin numbers

const unsigned long Code1    = 4010852096;
const unsigned long Code2   = 3994140416;
const unsigned long Code3   = 3977428736;
const unsigned long Code4   = 3944005376;
const unsigned long Code5     = 3927293696;
// saving ir codes



void setup() {
  Serial.begin(9600);
  IrReceiver.begin(2);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  // setting up and initialising libraries and components

}

void loop() {
  while(IrReceiver.decode()==0)
  {
  
  }
  if (IrReceiver.decode()) {
unsigned long code=IrReceiver.decodedIRData.decodedRawData;

    switch (code) {
      case Code1:
        setColor(255, 0, 0); // red
        break;
      case Code2 :
        setColor(0, 255, 0); // green
        break;
      case Code3:
        setColor(0,0,255); // blue
        break;
      case Code4:
        setColor(255, 255, 255); // white
        break;
      case Code5:
        turnOffLED();
        break;
      default:
        break;
    }
    IrReceiver.resume();
  }
}

void setColor(int RedColour, int GreenColour, int BlueColour) {
  analogWrite(red, RedColour);
  analogWrite(green, GreenColour);
  analogWrite(blue, BlueColour);
}

void turnOffLED() {
  setColor(0, 0, 0);
}