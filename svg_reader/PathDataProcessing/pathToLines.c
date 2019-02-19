#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include <string.h>
#include <stdlib.h>

const int MAX_VERTICES = 20;

const char SET_INIT_POINT = 'm';
const char LINE_TO = 'l';
const char HORIZONTAL_LINE_TO = 'h';
const char VERTICAL_LINE_TO = 'v';
const char CLOSE_SHAPE = 'z';


/**
 * getShapeFromInstructions:
 * @inst: the instructions from single path (shape) string
 * 
 * Converts a set of instructions into a Shape object
 * This function assumes that all instructions end with character z,
 * which closes the drawn shape (draws a line to the initial point).
 */
Shape getShapeFromInstructions(char* inst, float scale) {
    int nEdges = 0;
    Color shapeColor = Color_white();
    
    //[it][0] = i, [it][1] = j
    float** points = (float**) malloc (MAX_VERTICES * sizeof(float*));
    char* instructions = getInstructions(inst);
    char** numericValues = parseNumericValues(inst);
    int iInst = 0;

    // Instruction 'm', SET_INIT_POINT
    points[0] = parseToFloatPoint(numericValues[iInst]);
    iInst++;
    
    while(instructions[iInst] != CLOSE_SHAPE) {
        if(isThereComma(numericValues[iInst])) {
            // currPoint only applies to LINE_TO
            float* currPoint = parseToFloatPoint(numericValues[iInst]);
            points[iInst][0] = points[iInst-1][0] + currPoint[0];
            points[iInst][1] = points[iInst-1][1] + currPoint[1];
        } else {
            // Val only applies to HORIZONTAL_LINE_TO and VERTICAL_LINE_TO
            float val = strtof(numericValues[iInst], NULL);
            if(instructions[iInst] == HORIZONTAL_LINE_TO) {
                points[iInst][0] = points[iInst-1][0];
                points[iInst][1] = points[iInst-1][1] + val;
            } else if (instructions[iInst] == VERTICAL_LINE_TO) {
                points[iInst][0] = points[iInst-1][0] + val;
                points[iInst][1] = points[iInst-1][1];
            } 
        }
        iInst++;
    }

    Line *lines = constructLines(points, scale, iInst);
    

    return shape(lines, iInst, &shapeColor);
}

/**
 * getInstructions:
 * @inst: the instructions from a single shape string
 * 
 * Pulls out all the instructions (such as m, l, h, and v) and puts it into
 * an array of char.
 */
char* getInstructions(char* inst) {
    char *result = (char*) malloc(MAX_VERTICES*sizeof(char));
    int nInstructions = 0;
    while(*inst != CLOSE_SHAPE) {
        if( *inst == SET_INIT_POINT     ||
            *inst == LINE_TO            ||
            *inst == HORIZONTAL_LINE_TO ||
            *inst == VERTICAL_LINE_TO   ) {
                result[nInstructions++] = *inst;
            }
        inst++;
    }
    result[nInstructions] = CLOSE_SHAPE;
    return result;
}

/**
 * parseNumericValues:
 * @inst: the instructions from a single shape string
 * 
 * Pulls out all the numerical values and puts it into an
 * array of char. Points (x,y) are also considered as numeric values,
 * but is not parsed here. 
 */
char** parseNumericValues(char* inst) {
    int MAX_NUM_LENGTH = 40;
    char **result = (char**) malloc(MAX_VERTICES*sizeof(char*));
    int nNumbers = 0;
    int charIterator = 0;
    while (*inst != 'z') {
        if( *inst != SET_INIT_POINT     &&
            *inst != LINE_TO            &&
            *inst != HORIZONTAL_LINE_TO &&
            *inst != VERTICAL_LINE_TO   &&
            *inst != ' ') {
                result[nNumbers] = (char *) malloc (MAX_NUM_LENGTH * sizeof(char));
                while(*inst != ' ') {
                    result[nNumbers][charIterator++] = *inst;
                    inst++;
                }
                nNumbers++;
            } else {
                inst++;
        }
    }
}

/**
 * constructLines:
 * @points: an array of points in float, in order to maintain precision
 * @scale: how much of a scale to multiply
 * @nEdges: total amount of edges to make (equal to the total of points)
 * 
 * Constructs an array of line from given points.
 */
Line * constructLines(float** points, int scale, int nEdges) {
    Line * result = (Line*) malloc (nEdges * sizeof(Line));
    for(int it = 0; it < nEdges-1; it++) {
        Point point1 = floatToPointWithScale(points[it], scale);
        Point point2 = floatToPointWithScale(points[it + 1], scale);
        result[it] = line (point1, point2);
    }

    Point pointInit = floatToPointWithScale(points[0], scale);
    Point pointLast = floatToPointWithScale(points[nEdges-1], scale);
    result[nEdges-1] = line (pointLast, pointInit);
}

/**
 * isThereComma:
 * @val: given string
 * 
 * To check whether val is a point or not a point
 */
int isThereComma(char* val) {
    while(*val != ' ') {
        val++;
        if(*val == ',') return 0;
    }
    return 1;
}

/**
 * parseToFloatPoint:
 * @value: String to Parse
 * 
 * Returns a float with a size of 2. 
 * Does not use Point for precision reasons.
 * !!Coordinate flipping happens here!! 
 */
float* parseToFloatPoint(char* value) {
    char **splittedValue = splitPoint(value);
    //Karena sistem poin yang super aneh, yaitu (i,j), maka (x,y) dibalik jadi (y,x)
    float *point = (float*) malloc (2 * sizeof(float));
    point[0] = strtof(splittedValue[1], NULL); 
    point[1] = strtod(splittedValue[0], NULL);
    return point;
}

/**
 * splitPoint:
 * @value: point (string) to split
 * 
 * Splits a point(string) into two pieces.
 */
char** splitPoint (char* value) {
    const char DELIMITER = ',';

    // So the original string doesn't get modified by strtok
    // Not sure if needed, but just in case.
    char* processVal;
    strcpy(processVal, value); 
    
    // The first strtok gets the first point
    // The second strtok returns a pointer to the rest of the str 
    // (which is the second point)
    char ** result = (char *) malloc (2 * sizeof(char*));
    result[0] = strtok(processVal, DELIMITER);
    result[1] = strtok(NULL, DELIMITER);

    return result;
}

//To increase readability
Point floatToPointWithScale (float* value, float scale) {
    return point(value[0] * scale, value[1] * scale);
}