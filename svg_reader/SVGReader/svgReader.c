/**
 * SVG Reader
 */

#include "svgReader.h"
#include <string.h>

/**
 * getPathData:
 * @reader: the xmlReader
 * 
 * Extracts the "d" attribute in a node, if it is a "path".
 */
char*
getPathData(xmlTextReaderPtr reader) {
    const xmlChar* name;
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

char* getLayerName(xmlTextReaderPtr reader) {
    const xmlChar* name;
    const xmlChar* G_NODE_NAME = (const xmlChar*)"g";

    name = xmlTextReaderConstName(reader);
    if (name == NULL)
	name = BAD_CAST "--";

    if(xmlStrEqual(name, G_NODE_NAME)) {
        return (char *)xmlTextReaderGetAttributeNs(reader,(const xmlChar*) "id",NULL);
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
streamFile(const char *filename, char ** outLayerNames) {
    xmlTextReaderPtr reader;
    int ret;
    const int RESULT_SIZE = 160; //integer incase of needing to realloc
    int nShapes = 0;
    int nLayer = 0;

    char** result = (char**) malloc (RESULT_SIZE * sizeof(char*));
    
    reader = xmlReaderForFile(filename, NULL, 0);
    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);
        while (ret == 1) {
            char* pathData = getPathData(reader);
            if(getLayerName(reader) != NULL) {
                if (nLayer == 0) {
                    outLayerNames[nLayer++] = getLayerName(reader);
                } else
                //if outLayernames != getLayerName
                if(strcmp(outLayerNames[nLayer - 1],getLayerName(reader))){
                    //give a gap, so we know when the layer changes.
                    result[nShapes++] = NULL;
                    outLayerNames[nLayer++] = getLayerName(reader);
                }
            }
            
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
