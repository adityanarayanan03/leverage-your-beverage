#include "parse_move.h"

Servo pan;
Servo tilt;
char panStr[4] = {0, 0, 0, 0};
char tiltStr[4] = {0, 0, 0, 0};
char data[10];
int panAngle = 0;
int tiltAngle = 0;

void parse() {
	if (Serial.available() > 0) {
		uint8_t it = Serial.readBytesUntil('\0', data, 9);
		Serial.println(it);
		memcpy(panStr, &data[0], 3 * sizeof(char));
		memcpy(tiltStr, &data[3], 3 * sizeof(char));
		panAngle = threeDigitNum(panStr);
		tiltAngle = threeDigitNum(tiltStr);
		Serial.print(panAngle); Serial.print(" "); Serial.println(tiltAngle);
	}
	pan.write(panAngle);
	tilt.write(tiltAngle);
}