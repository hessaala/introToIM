int buttonSwitch = A2;
int potentiometer = A0;
int ledOut = 11;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  digitalWrite(ledOut, LOW);  // in the case of reconnection while p5 is running
  // start the handshake
  while (Serial.available() <= 0) {
    Serial.println("-1,-1");  // send a starting message
    delay(300);               // wait 1/3 second
  }
}

void loop() {
  // wait for data from p5 before doing something
  while (Serial.available()) {
    int hit = Serial.parseInt(); // receives 1 argument, whether the ball hit the ground
    if (Serial.read() == '\n') {
      digitalWrite(ledOut, hit); // turn on LED if the ball is in contact with the ground (1 -> HIGH) turn off LED if not (0, -> LOW)
      int sensor = digitalRead(buttonSwitch); // read button
      delay(1);
      int sensor2 = analogRead(potentiometer); // read potentiometer
      delay(1);
      Serial.print(sensor); // button
      Serial.print(',');
      if (sensor2 < 512) { // potentiometer; depending whether the value is over or below half, direction of the wind is set
        Serial.println(1);
      } else {
        Serial.println(-1);
      }
    }
  }
}
