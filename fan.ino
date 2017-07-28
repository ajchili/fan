#include <IRremote.h>

int fanState = 0;
bool light = false;

bool fanButton = false;
bool lightButton = false;

IRrecv irrecv(7);
decode_results results;

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(12, INPUT);
  irrecv.enableIRIn();
}

void loop() {
  parseInput();
  displayState();

  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  
  delay(1);
}

void serialEvent() {
  String data = Serial.readString();
  parseSerialInput(data);
}

void displayState() {
  displayLightState();
  displayFanState();
}

void parseInput() {
  parseArduinoInput();
}

void displayLightState() {
  if (light) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
}

void displayFanState() {
  switch(fanState) {
    case 1:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
    case 2:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      break;
    case 3:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      break;
    default:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
  }
}

void parseArduinoInput() {
  if (!fanButton && digitalRead(5) == HIGH) {
    fanState < 3 ? fanState++ : fanState = 0;
    fanButton = true;
  } else {
    fanButton = (digitalRead(5) == HIGH);
  }

  if (!lightButton && digitalRead(12) == HIGH) {
    light ? light = false : light = true;
    lightButton = true;
  } else {
    lightButton = (digitalRead(12) == HIGH);
  }
}

void parseSerialInput(String data) {
  if (data.substring(0, 1).equals("f")) {
    fanState = data.substring(1, 2).toInt();
  } else if (data.substring(0, 1).equals("l")) {
    light ? light = false : light = true;
  }
}

