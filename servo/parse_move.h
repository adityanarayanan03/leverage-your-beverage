#ifndef PARSE_MOVE_H
#define PARSE_MOVE_H

/**
 * parse_input parses Serial input and converts to two angles
 * Serial input expects two angles given in three digits, concatenated
 *  ie. angles 45 and 90 : Serial 045090
 */
void parse_input(int *panAngle, int *tiltAngle);

#endif // PARSE_MOVE_H
