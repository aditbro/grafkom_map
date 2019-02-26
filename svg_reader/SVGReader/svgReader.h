/**
 * SVG Reader
 */

#include <stdio.h>
#include <libxml/xmlreader.h>

#ifdef LIBXML_READER_ENABLED


/**
 * getPathData:
 * @reader: the xmlReader
 * 
 * Extracts the "d" attribute in a node, if it is a "path".
 */
char*
getPathData(xmlTextReaderPtr reader);


char* 
getLayerName(xmlTextReaderPtr reader);
/**
 * streamFile:
 * @filename: the file name to parse
 * @outLayerNames: output layer names corresponding to return value
 *
 * Parses SVG and returns an array of string that represents unprocessed path data
 */
char**
streamFile(const char *filename, char** outLayerNames);

#endif