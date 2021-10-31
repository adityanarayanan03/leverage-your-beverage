#include 

void setup() {
	Serial.begin(115200);
	pan.attach(5);
	tilt.attach(6);
	pinMode(LED_BUILTIN, OUTPUT);
}

void heartbeat() {
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
}

void loop() {
	heartbeat();
}