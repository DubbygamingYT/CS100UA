#include <stdio.h>
#include <ctype.h> // for isalpha()
#include <string.h> // for string manipulation

#define MAX_LENGTH 50

int main(int argc, char **argv) 
{
    if (argc != 3) 
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "r"); //read only
    if (inputFile == 0) {
        printf("Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    // Open the output file
    FILE *outputFile = fopen(argv[2], "w"); //writes file 
    if (outputFile == 0) {
        printf("Cannot open file '%s'\n", argv[2]);
        fclose(inputFile); // Close the input file since it was opened successfully
        return 1;
    }

    char str[MAX_LENGTH];

    // Read each string from the file
    while (fscanf(inputFile, "%s", str) != EOF) {
        int valid = 1;
        for (int i = 0; i < strlen(str); i++) {
            if (!isalpha(str[i])) {
                valid = 0; // Mark as invalid if non-alphabetic character is found
                break;
            }
        }

        // If the string is valid, print it and write to the output file
        if (valid) {
            printf("%s ", str);
            fprintf(outputFile, "%s ", str);
        }
    }
    printf("\n");
    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
