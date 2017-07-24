int fanState = 0;
bool light = false;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  writeLightState();
  writeFanState();
  
  delay(250);

  fanState < 2 ? fanState++ : fanState = 0;
  light ? light = false : light = true;
}

void writeLightState() {
  if (light) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
}

void writeFanState() {
  switch(fanState) {
    case 0:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
    case 1:
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      break;
    case 2:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      break;
    default:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
  }
}

