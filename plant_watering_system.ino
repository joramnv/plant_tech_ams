#define ANA A0
#define DIGI D5
#define POMPOUT D6
double analogValue = 0.0;
int digitalValue = 0;
double analogVolts = 0.0;
unsigned long previousMillis = 0;
unsigned long intervalMillis = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ANA, INPUT);
  pinMode(DIGI, INPUT);
  pinMode(POMPOUT, OUTPUT);
  Serial.begin(115200);
  Serial.println("Paolo Test");
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= intervalMillis) {
    analogValue = analogRead(ANA);
    digitalValue = digitalRead(DIGI);
    // Serial data
    Serial.print("Analog raw: ");
    Serial.println(analogValue);
    Serial.print("Digital raw: ");
    Serial.println(digitalValue);
    Serial.println(" ");
    if (analogValue < 600) {
      digitalWrite(POMPOUT, false);
      //delay(5000);
      intervalMillis = 5000;
    } else {
      Serial.println("PUMPIN");
      digitalWrite(POMPOUT, true);
      //delay(1000);
      intervalMillis = 1000;
    }
    previousMillis = currentMillis;
  }
}
