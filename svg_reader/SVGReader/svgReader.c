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
static char*
getPathData(xmlTextReaderPtr reader) {
    const xmlChar *name, *value;
    const xmlChar* PATH_NODE_NAME = (const xmlChar*)"path";
    char* result;

    name = xmlTextReaderConstName(reader);
    if (name == NULL)
	name = BAD_CAST "--";

    if(xmlStrEqual(name, PATH_NODE_NAME)) {
        return xmlTextReaderGetAttributeNs(reader,"d",NULL);
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
static char**
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
                //Print For debugging
                //TODO: delete this part
                printf("[%d] %s\n", nShapes + 1, pathData);
                ///////////////////////////////////////////
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
}

/*
 * Main for Testing
 * TODO: Delete this part
 */
int main(int argc, char **argv) {
    if (argc != 2)
        return(1);

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    streamFile(argv[1]);

    /*
     * Cleanup function for the XML library.
     */
    xmlCleanupParser();
    /*
     * this is to debug memory for regression tests
     */
    xmlMemoryDump();
    return(0);
}
