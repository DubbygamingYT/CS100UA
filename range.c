#include <stdio.h>
#include <stdlib.h> //for atof
#include <float.h> //DBL_MIN and DBL_MAX


int main(int argc, char **argv)
{
    double max = -DBL_MAX;
    double min = DBL_MAX;

    if (argc == 1)
    {
        printf("This program requires at least one argument\n");
        return 1;
    }
    if (argc >= 2)
    {
    // Loop through each argument
        for (int i = 1; i < argc; i++) {
            double num = atof(argv[i]);

            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
        double range = max - min;
        printf("The range of these %d values is %.6f\n",argc-1, range);
    }

    return 0;
}