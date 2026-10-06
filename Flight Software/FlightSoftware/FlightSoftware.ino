#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SD.h>
#include <ESP32Servo.h>
#include <SPI.h>
#include <LittleFS.h>
#include <Preferences.h>
#include <Adafruit_BNO08x.h>


//int PowerCycle = 0;
Servo ServoPosX;
Servo ServoNegX;
Servo ServoPosY;
Servo ServoNegY;
#define Buzzer 4
#define GLED 12
#define RLED 13
int State = 0;
#define CardReader 5
Adafruit_BNO08x bno08x;

/*
void syncFlashToSD() {
  File root = LittleFS.open("/");
  File file = root.openNextFile();

  while (file) {
    String fileName = file.name();
    String fullPath = "/" + fileName; // LittleFS.name() sometimes omits leading slash

    Serial.print("Checking flash file: ");
    Serial.println(fullPath);

    if (!SD.exists(fullPath)) {
      Serial.println("Not found on SD, copying...");
      copyFileToSD(fullPath);
    } else {
      Serial.println("Already exists on SD, skipping");
    }

    file = root.openNextFile();
  }
}

void copyFileToSD(String path) {
  File sourceFile = LittleFS.open(path, "r");
  if (!sourceFile) {
    Serial.println("Failed to open source file on flash");
    return;
  }

  File destFile = SD.open(path, FILE_WRITE);
  if (!destFile) {
    Serial.println("Failed to create destination file on SD");
    sourceFile.close();
    return;
  }

  while (sourceFile.available()) {
    destFile.write(sourceFile.read());
  }

  sourceFile.close();
  destFile.close();

  Serial.print("Copied: ");
  Serial.println(path);
}
 */    


void setup() {
Serial.begin(9600);
delay(500);
Wire.begin();
pinMode(Buzzer, OUTPUT);
pinMode(GLED, OUTPUT);
pinMode(RLED, OUTPUT);

 digitalWrite(RLED, HIGH);
 digitalWrite(GLED, HIGH);
 tone(Buzzer, 2794);
 delay(100);
 digitalWrite(RLED, LOW);
 digitalWrite(GLED, LOW);
 noTone(Buzzer);
 delay(100);
 digitalWrite(RLED, HIGH);
 digitalWrite(GLED, HIGH);
 tone(Buzzer, 2794);
 delay(100);
 noTone(Buzzer);
 digitalWrite(RLED, LOW);
 digitalWrite(GLED, LOW);
 
 
  if (!SD.begin(CardReader)) {
    Serial.println("SD Card Initialization Failed");
    State  = 10;
    return;
  }

  if (!bno08x.begin_I2C(0x4B)) {
  Serial.println("BNO08x Initialization Failed");
  State = 10;
  return;
}

  //EDF/ESC Check Maybe
  
  
  //Update Cycle Counter
 // prefs.begin("myApp", false); // false = read/write mode
 // PowerCycle = prefs.getInt("powerCycle", 0);
 // PowerCycle++;
 // prefs.putInt("powerCycle", PowerCycle);
// prefs.end();

  //Update Files on SD
 // syncFlashToSD();

  //Servo Tests
  ServoPosX.attach(27);
  ServoPosX.write(90);
  delay(250);
  ServoPosX.write(50);
  delay(250);
  ServoPosX.write(90);
  delay(250);
  ServoPosX.write(140);
  delay(250);
  ServoPosX.write(90);
  delay(500);

  ServoNegX.attach(26);
  ServoNegX.write(90);
  delay(250);
  ServoNegX.write(50);
  delay(250);
  ServoNegX.write(90);
  delay(250);
  ServoNegX.write(140);
  delay(250);
  ServoNegX.write(90);
  delay(500);

  ServoPosY.attach(25);
  ServoPosY.write(90);
  delay(250);
  ServoPosY.write(50);
  delay(250);
  ServoPosY.write(90);
  delay(250);
  ServoPosY.write(140);
  delay(250);
  ServoPosY.write(90);
  delay(500);

  ServoNegY.attach(33);
  ServoNegY.write(90);
  delay(250);
  ServoNegY.write(50);
  delay(250);
  ServoNegY.write(90);
  delay(250);
  ServoNegY.write(140);
  delay(250);
  ServoNegY.write(90);
  delay(500);

  ServoPosX.write(50);
  ServoNegX.write(50);
  delay(250);
  ServoPosX.write(90);
  ServoNegX.write(90);
  delay(250);
  ServoPosX.write(140);
  ServoNegX.write(140);
  delay(250);
  ServoPosX.write(90);
  ServoNegX.write(90);
  delay(500);

  ServoPosY.write(50);
  ServoNegY.write(50);
  delay(250);
  ServoPosY.write(90);
  ServoNegY.write(90);
  delay(250);
  ServoPosY.write(140);
  ServoNegY.write(140);
  delay(250);
  ServoPosY.write(90);
  ServoNegY.write(90);
  delay(400);

  


  //Buzzer Start
 digitalWrite(RLED, HIGH);
 digitalWrite(GLED, HIGH);
 tone(Buzzer, 2794);
 delay(100);
 digitalWrite(RLED, LOW);
 digitalWrite(GLED, LOW);
 noTone(Buzzer);
 delay(100);
 digitalWrite(RLED, HIGH);
 digitalWrite(GLED, HIGH);
 tone(Buzzer, 2794);
 delay(100);
 noTone(Buzzer);
 digitalWrite(RLED, LOW);
 digitalWrite(GLED, LOW);

  delay(500);
  State = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(State) {

  

 case 10:
 digitalWrite(RLED, HIGH);
 tone(Buzzer, 131);
 delay(500);
 digitalWrite(RLED, LOW);
 noTone(Buzzer);
 delay(1000);
 break;
  }
}
