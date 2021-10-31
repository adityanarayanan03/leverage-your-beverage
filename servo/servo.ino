#include "config.h"
#include "parse_move.h"
#include <Servo.h>

Servo pan;
Servo tilt;

void setup() {
	Serial.begin(115200);
	pan.attach(5);
	tilt.attach(6);
	pinMode(LED_BUILTIN, OUTPUT);
}

int panAngle, tiltAngle;

void heartbeat() {
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
}

void loop() {
	heartbeat();
  parse_input(&panAngle, &tiltAngle);
  //parse_debug();
  pan.write(panAngle);
  tilt.write(tiltAngle);
}
