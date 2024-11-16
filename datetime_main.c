#include <stdio.h>
#include <stdlib.h>

#include "datetime.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
       printf("Usage: %s src_datetime_filename dest_datetime_filename\n", argv[0]);
       return 1;
    }
    char *srcDateTimeFilename = argv[1];
    char *destDateTimeFilename = argv[2];
    
    int size;
    DateTime *dts = readDateTimes(srcDateTimeFilename, &size);
    
    if (dts == NULL) {
       printf("Unable to open file '%s' for read\n", srcDateTimeFilename);
       return 2;
    }
    
    if (!writeValidDateTimes(destDateTimeFilename, dts, size)) {
       printf("Unable to open file '%s' for write\n", destDateTimeFilename);
       return 3;
    }
    
    free(dts);

    return 0;
}
