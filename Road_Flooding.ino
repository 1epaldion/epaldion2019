
// HARDWARE

#include <Servo.h>
#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

Servo myservo;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);

int pos = 0;
const int greenled = 9;
const int yellowled = 10;
const int redled = 11;
const int waterSens = A0;
//const int RELAY_PIN = A3;  // the Arduino pin, which connects to the IN pin of relay
int waterVal;


void setup(){
  lcd.begin (16,2); // 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
  lcd.setBacklight(HIGH);
  //Startup-----------------
  lcd.print("Starting.");
  delay(1000);
  lcd.clear();
  lcd.print("Starting..");
  delay(1000);
  lcd.clear();
  lcd.print("Starting...");
  delay(3000);
  lcd.clear();
  lcd.print("Done");
  delay(1000);
  lcd.clear();
  //------------------------
  pinMode(waterSens, INPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(redled, OUTPUT);
  //pinMode(RELAY_PIN, OUTPUT);
  //digitalWrite(RELAY_PIN, LOW);
  Serial.begin(9600);

  myservo.attach(8);
}

void loop() {
   waterVal = analogRead(waterSens);

   Serial.println(waterVal);
   
if(waterVal <= 150){
  lcd.clear();
  digitalWrite(greenled,HIGH);
  digitalWrite(yellowled,LOW);
  digitalWrite(redled,LOW);
  myservo.write(90);
}                                                                                           
if(waterVal > 150 && waterVal <= 275){
  lcd.clear();
  digitalWrite(greenled,LOW);
  digitalWrite(yellowled,HIGH);
  digitalWrite(redled,LOW);
  myservo.write(90);
  lcd.setCursor(4,0);
  lcd.print("[Caution]");
  delay(1000);
  lcd.setCursor(2,1);
  lcd.print("Road Unsafe");
  delay(2000);
  lcd.clear();
  
}

if(waterVal > 275){
  lcd.clear();
  digitalWrite(greenled,LOW);
  digitalWrite(yellowled,LOW);
  digitalWrite(redled,HIGH);
  myservo.write(180);
  lcd.setCursor(4,0);
  lcd.print("[DANGER]");
  delay(1000);
  //digitalWrite(RELAY_PIN, HIGH); // turn on pump 5 seconds
  //delay(2000);
  //digitalWrite(RELAY_PIN, LOW);  // turn off pump 5 seconds
  lcd.setCursor(2,1);
  lcd.print("Road Flooded!");
}

}


