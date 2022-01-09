// Code designed for Arduino Uno R3

const int NUMBER_OF_CIRCUITS = 3;
const int ANALOG_INPUTS[NUMBER_OF_CIRCUITS] = { A2, A1, A0 };
const int LED_OUTPUTS[NUMBER_OF_CIRCUITS] = { 2, 3, 4 };
const int ALLOWED_DELTA = 100;

void setup() {
  Serial.begin(9600); // for debug
  delay(1000);
  
  pinMode(LED_BUILTIN, OUTPUT);

  for (int i=0; i<NUMBER_OF_CIRCUITS; i++) {
    pinMode(LED_OUTPUTS[i], OUTPUT);
  }

  Serial.println("Ready");
}


void loop() {
  for (int i=0; i<NUMBER_OF_CIRCUITS; i++) {
    const int val = analogRead(ANALOG_INPUTS[i]);
    Serial.print(val);
    Serial.print(" ");
    if (val > 512 - ALLOWED_DELTA && val < 512 + ALLOWED_DELTA) {
      digitalWrite(LED_OUTPUTS[i], HIGH);
    } else {
      digitalWrite(LED_OUTPUTS[i], LOW);
    }
  }
  Serial.println("");

  delay(100);
}
