#include <Servo.h>

Servo pan;
Servo tilt;

void setup() {
	Serial.begin(115200);
	pan.attach(5);
	tilt.attach(6);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	pan.write(60);
	tilt.write(60);
	delay(300);
	digitalWrite(LED_BUILTIN, HIGH);
	pan.write(120);
	tilt.write(120);
	delay(300);
	digitalWrite(LED_BUILTIN, LOW);
}