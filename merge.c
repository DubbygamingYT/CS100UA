#include <stdio.h>
#include <stdlib.h> // for exit()

int main(int argc, char **argv) {
    if (argc != 3) 
    {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    // Open the two files
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == 0) 
    {
        printf("Cannot open file '%s'\n", argv[1]);
        return 1;
    }
    if (file2 == 0) 
    {
        printf("Cannot open file '%s'\n", argv[2]);
        fclose(file1); // Close file1 if file2 cannot be opened
        return 1;
    }

    int num1, num2;
    int readFile1 = fscanf(file1, "%d", &num1);
    int readFile2 = fscanf(file2, "%d", &num2);

    // Merge both files
    while (readFile1 != EOF && readFile2 != EOF)
     {
        if (num1 < num2) {
            printf("%d\n", num1);
            readFile1 = fscanf(file1, "%d", &num1);
        } else if (num1 > num2) {
            printf("%d\n", num2);
            readFile2 = fscanf(file2, "%d", &num2);
        } else {
            // Both numbers are equal, print once and read the next from both files
            printf("%d\n", num1);
            readFile1 = fscanf(file1, "%d", &num1);
            readFile2 = fscanf(file2, "%d", &num2);
        }
    }

    // If file1 still has numbers
    while (readFile1 != EOF) 
    {
        printf("%d\n", num1);
        readFile1 = fscanf(file1, "%d", &num1);
    }

    // If file2 still has numbers
    while (readFile2 != EOF) 
    {
        printf("%d\n", num2);
        readFile2 = fscanf(file2, "%d", &num2);
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}
