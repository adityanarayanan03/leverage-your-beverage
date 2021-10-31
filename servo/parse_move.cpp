#include "parse_move.h"
#include "config.h"
#include <arduino.h>

char panStr[4] = {0, 0, 0, 0};
char tiltStr[4] = {0, 0, 0, 0};
char data[10];

/**
 * turns a 3-length number c-string into an integer
 * validates output for servo angles (0 degrees to 180)
 * if number is invalid, returns 90
 * null terminator not needed
 */
static int threeDigitNum(const char* str) {
  int output = 100 * (str[0] - '0') + 10 * (str[1] - '0') + (str[2] - '0');
  if (output < ANGLELOW) output = ANGLELOW;
  if (output > ANGLEHIGH) output = ANGLEHIGH;
  return output;
}

/**
 * parse_input parses Serial input and converts to two angles
 * Serial input expects two angles given in three digits, concatenated
 *  ie. angles 45 and 90 : Serial 045090
 */
void parse_input(int *panAngle, int *tiltAngle) {
	if (Serial.available() > 0) {
		int it = Serial.readBytesUntil('\0', data, 9);
    if (DEBUG) {
		  // Serial.println(it);
    }
		memcpy(panStr, &data[0], 3 * sizeof(char));
		memcpy(tiltStr, &data[3], 3 * sizeof(char));
		*panAngle = threeDigitNum(panStr);
		*tiltAngle = threeDigitNum(tiltStr);
    if (DEBUG) {
		  Serial.print(*panAngle); Serial.print(" "); Serial.println(*tiltAngle);
    }
	}
}
