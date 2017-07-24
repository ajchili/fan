int fanState = 0;
bool light = false;

bool fanButton = false;
bool lightButton = false;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  parseInput();
  displayState();
  
  delay(1);

  // Code for testing
  // fanState < 2 ? fanState++ : fanState = 0;
  // light ? light = false : light = true;
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

