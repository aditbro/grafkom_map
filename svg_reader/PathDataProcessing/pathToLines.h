#ifndef PATH_TO_LINES_H
#define PATH_TO_LINES_H
// #include "Line/Line.h"
// #include "Point/Point.h"
// #include "Shape/Shape.h"
#include "../../data_structures.h"


/**
 * getShapeFromInstructions:
 * @inst: the instructions from single path (shape) string
 * 
 * Converts a set of instructions into a Shape object
 * This function assumes that all instructions end with character z,
 * which closes the drawn shape (draws a line to the initial point).
 */
Shape getShapeFromInstructions(char* inst, float scale);

/**
 * getInstructions:
 * @inst: the instructions from a single shape string
 * 
 * Pulls out all the instructions (such as m, l, h, and v) and puts it into
 * an array of char.
 */
char* getInstructions(char* inst);

/**
 * parseNumericValues:
 * @inst: the instructions from a single shape string
 * 
 * Pulls out all the numerical values and puts it into an
 * array of char. Points (x,y) are also considered as numeric values,
 * but is not parsed here. 
 */
char** parseNumericValues(char* inst);

/**
 * constructLines:
 * @points: an array of points in float, in order to maintain precision
 * @scale: how much of a scale to multiply
 * @nEdges: total amount of edges to make (equal to the total of points)
 * 
 * Constructs an array of line from given points.
 */
Line * constructLines(float** points, int scale, int nEdges);

/**
 * isThereComma:
 * @val: given string
 * 
 * To check whether val is a point or not a point
 */
int isThereComma(char* val);

/**
 * parseToFloatPoint:
 * @value: String to Parse
 * 
 * Returns a float with a size of 2. 
 * Does not use Point for precision reasons.
 * !!Coordinate flipping happens here!! 
 */
float* parseToFloatPoint(char* value);

/**
 * splitPoint:
 * @value: point (string) to split
 * 
 * Splits a point(string) into two pieces.
 */
char** splitPoint (char* value);

//To increase readability
Point floatToPointWithScale (float* value, float scale);

#endif