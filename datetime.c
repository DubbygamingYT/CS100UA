#include <stdio.h>
#include <stdlib.h>

#include "datetime.h"

// return 0 if the date is invalid
// return not 0 if the date is valid
// the year cannot be negative; do not account for leap years
int isValidDate(const Date *date) {
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (date->year < 0) return 0; // Invalid year
    if (date->month < 1 || date->month > 12) return 0; // Invalid month
    if (date->day < 1 || date->day > daysInMonth[date->month]) return 0; // Invalid day

    return 1; // Valid date
}

// return 0 if the time is invalid
// return not 0 if the time is valid
// valid times are 00:00:00 - 23:59:59
int isValidTime(const Time *time) {
    if (time->hour < 0 || time->hour > 23) return 0; // Invalid hour
    if (time->min < 0 || time->min > 59) return 0; // Invalid minute
    if (time->sec < 0 || time->sec > 59) return 0; // Invalid second

    return 1; // Valid time
}

// return 0 if the datetime is invalid
// return not 0 if the datetime is valid
int isValidDateTime(const DateTime *dt) {
    return isValidDate(&dt->date) && isValidTime(&dt->time);
}

// return NULL and size 0 if the file cannot be opened
// return the array of datetimes and the size otherwise
// datetimes will be formatted as yyyy-MM-dd HH:mm:ss
// you can use the pattern "%d-%d-%d %d:%d:%d" to scan
DateTime *readDateTimes(const char filename[], int *refSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        *refSize = 0;
        return NULL;
    }

    fscanf(file, "%d", refSize);
    DateTime *dts = (DateTime *)malloc(*refSize * sizeof(DateTime));
    if (!dts) {
        fclose(file);
        *refSize = 0;
        return NULL;
    }

    for (int i = 0; i < *refSize; i++) {
        fscanf(file, "%d-%d-%d %d:%d:%d",
               &dts[i].date.year, &dts[i].date.month, &dts[i].date.day,
               &dts[i].time.hour, &dts[i].time.min, &dts[i].time.sec);
    }

    fclose(file);
    return dts;
}

// return 0 if the file cannot be opened
// return not 0 if the file can be opened
// write one valid datetime per line formatted as yyyy-MM-dd HH:mm:ss
// you can use the pattern "%04d-%02d-%02d %02d:%02d:%02d"
int writeValidDateTimes(const char filename[], const DateTime dts[], const int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return 0;
    }

    int validCount = 0;
    for (int i = 0; i < size; i++) {
        if (isValidDateTime(&dts[i])) {
            validCount++;
        }
    }

    fprintf(file, "%d\n", validCount);
    for (int i = 0; i < size; i++) {
        if (isValidDateTime(&dts[i])) {
            fprintf(file, "%04d-%02d-%02d %02d:%02d:%02d\n",
                    dts[i].date.year, dts[i].date.month, dts[i].date.day,
                    dts[i].time.hour, dts[i].time.min, dts[i].time.sec);
        }
    }

    fclose(file);
    return 1;
}
