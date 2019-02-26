/**
 * SVG Reader
 */

#include "svgReader.h"

/**
 * getPathData:
 * @reader: the xmlReader
 * 
 * Extracts the "d" attribute in a node, if it is a "path".
 */
char*
getPathData(xmlTextReaderPtr reader) {
    const xmlChar *name;
    const xmlChar* PATH_NODE_NAME = (const xmlChar*)"path";

    name = xmlTextReaderConstName(reader);
    if (name == NULL)
	name = BAD_CAST "--";

    if(xmlStrEqual(name, PATH_NODE_NAME)) {
        return (char *)xmlTextReaderGetAttributeNs(reader,(const xmlChar*) "d",NULL);
    } else {
        return NULL;
    }
}

/**
 * streamFile:
 * @filename: the file name to parse
 *
 * Parses SVG and returns an array of string that represents unprocessed path data
 */
char**
streamFile(const char *filename) {
    xmlTextReaderPtr reader;
    int ret;
    int RESULT_SIZE = 80; //integer incase of needing to realloc

    int nShapes = 0;

    char** result = (char**) malloc (RESULT_SIZE * sizeof(char*));
    reader = xmlReaderForFile(filename, NULL, 0);
    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);
        while (ret == 1) {
            char* pathData = getPathData(reader);
            if(pathData != NULL) {
                result[nShapes++] = pathData;
            }
            ret = xmlTextReaderRead(reader);
        }
        xmlFreeTextReader(reader);
        if (ret != 0) {
            fprintf(stderr, "%s : failed to parse\n", filename);
        }
    } else {
        fprintf(stderr, "Unable to open %s\n", filename);
    }
    return result;
}
