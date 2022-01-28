// Code designed for Arduino Uno R3

// Uses https://github.com/ridencww/cww_MorseTx 1.2.0
#include <cww_MorseTx.h>

const int NUMBER_OF_CIRCUITS = 3;
const int ANALOG_INPUTS[NUMBER_OF_CIRCUITS] = { A2, A1, A0 };
const int LED_OUTPUTS[NUMBER_OF_CIRCUITS] = { 2, 3, 4 };
const int ALLOWED_DELTA = 100;
const int SECONDS_CONTACT_BEFORE_CONSIDERED_SOLVED = 5;

// Morse settings
const int BUZZER_PIN = 7;
const int CW_SPEED = 5; // morse speed
const int TONE_FREQ = 500; // buzze tone Hz
cww_MorseTx morse(LED_BUILTIN, CW_SPEED, BUZZER_PIN, TONE_FREQ);

// Secret message to transmit when puzzle is solved
#define SECRET_MESSAGE "VOLET"

unsigned long solvedSince = 0;

void setup() {
  Serial.begin(9600); // for debug
  delay(1000);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  for (int i=0; i<NUMBER_OF_CIRCUITS; i++) {
    pinMode(LED_OUTPUTS[i], OUTPUT);
  }

  Serial.println("Ready");
}

void loop() {
  bool solved = true;
  for (int i=0; i<NUMBER_OF_CIRCUITS; i++) {
    const int val = analogRead(ANALOG_INPUTS[i]);
    //Serial.print(val);
    //Serial.print(" ");
    if (val > 512 - ALLOWED_DELTA && val < 512 + ALLOWED_DELTA) {
      digitalWrite(LED_OUTPUTS[i], HIGH);
    } else {
      solved = false;
      digitalWrite(LED_OUTPUTS[i], LOW);
    }
  }
  //Serial.println("");

  if (solved) {
    if (solvedSince == 0) {
      solvedSince = millis();
    }
  } else {
    solvedSince = 0;
  }

  if (solvedSince != 0 && millis() > solvedSince + 1000*SECONDS_CONTACT_BEFORE_CONSIDERED_SOLVED) {
    morse.send(SECRET_MESSAGE);
    delay(5000);
  }
  
  delay(100);
}
