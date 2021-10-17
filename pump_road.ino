const int RELAY_PIN = A5;  // the Arduino pin, which connects to the IN pin of relay
const int SENSOR_PIN = A0;  // the Arduino pin, which connects to the IN pin of relay

int waterVal; // the water level value

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  waterVal = analogRead(SENSOR_PIN);
  
  delay(10);
  Serial.println(waterVal);
  
  if (waterVal > 275){
    digitalWrite(RELAY_PIN, LOW); // turn on pump 5 seconds
  } else {
    digitalWrite(RELAY_PIN, HIGH);
  }
  
  delay(100);
}
