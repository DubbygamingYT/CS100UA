#ifndef _DATETIME_H_
#define _DATETIME_H_

typedef struct _date {
    int day;
    int month;
    int year;
} Date;

typedef struct _time {
    int sec;
    int min;
    int hour;
} Time;

typedef struct _dateTime {
    Date date;
    Time time;
} DateTime;

int isValidDate(const Date *date);
int isValidTime(const Time *time);
int isValidDateTime(const DateTime *dt);

DateTime *readDateTimes(const char filename[], int *refSize);
int writeValidDateTimes(const char filename[], const DateTime dts[], const int size);

#endif