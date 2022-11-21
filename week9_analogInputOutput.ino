const int blueLEDPin = 3;
const int yellowLEDPin = 7;

void setup() {
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {

  int switchPosition = digitalRead(2);

  int analogValue = analogRead(A0);
  int brightness = map(analogValue, 0, 1023, 0, 255);


 
  if (switchPosition == HIGH) {
    digitalWrite(yellowLEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else  {
    digitalWrite(yellowLEDPin, LOW);    // turn the LED off by making the voltage LOW
  }

  Serial.print("Analog reading: ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined           
  if (brightness < 25) {
    Serial.println(" - Dark");
    analogWrite(blueLEDPin, 0);
  } else if (brightness < 50) {
    Serial.println(" - Dim");
    analogWrite(blueLEDPin, 10);
  } else if (brightness < 100) {
    Serial.println(" - Light");
    analogWrite(blueLEDPin, 80);
  } else if (brightness < 255) {
    Serial.println(" - Bright");
    analogWrite(blueLEDPin, 255);
  } else {
    Serial.println(" - Very bright");
  }


}
