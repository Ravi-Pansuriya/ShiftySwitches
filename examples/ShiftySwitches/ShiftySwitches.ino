#include <ShiftySwitches.h>

// Prepare set of unique device Ids
const char* light1 = "abc";
const char* light2 = "xyz";
const char* light3 = "111";

int dataPin = 13;
int clockPin = 14; 
int latchPin = 12;

bool defaultOutput = true;

ShiftySwitches switches(defaultOutput, dataPin, clockPin, latchPin); // Default is (false, 13, 14, 12);

void setup() {
  Serial.begin(115200);
  
  // Add switch ids (max 8)
  // To allow more then 8 you have to change MAX_SWITCHES. (8 * NoOfShiftResistors)
  switches.add(light1, 0);
  switches.add(light2, 1);
  switches.add(light3, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  switches.turnOn(light1);
  delay(1000);
  switches.turnOff(light2);
  delay(1000);
  switches.toggle(light3);
  delay(1000);
  switches.toggleAll();
  delay(1000);
  switches.turnAllOn();
  delay(1000);
  switches.turnAllOff();
  delay(1000);
}
