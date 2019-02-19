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
static char*
getPathData(xmlTextReaderPtr reader);

/**
 * streamFile:
 * @filename: the file name to parse
 *
 * Parses SVG and returns an array of string that represents unprocessed path data
 */
static char**
streamFile(const char *filename);

#endif