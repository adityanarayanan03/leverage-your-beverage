#include "parse_move.h"
#include "config.h"
#include <arduino.h>

char panStr[4] = {0, 0, 0, 0};
char tiltStr[4] = {0, 0, 0, 0};
char data[10];

static inline int threeDigitNum(const char* str) {
  return 100 * (str[0] - '0') + 10 * (str[1] - '0') + (str[2] - '0');
}

void parse_input(int *panAngle, int *tiltAngle) {
	if (Serial.available() > 0) {
		int it = Serial.readBytesUntil('\0', data, 9);
    if (DEBUG) {
		  Serial.println(it);
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
