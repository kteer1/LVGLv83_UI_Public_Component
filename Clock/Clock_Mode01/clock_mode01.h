#ifndef ___kCLOCK_MODE01_H__
#define ___kCLOCK_MODE01_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint8_t system;
}clockmode01_time_s;

#define CLOCKMODE01_Deflaut(dhour,dmin,dsec,dsystem)       \
{                                               \
    .hour = dhour,                               \
    .min = dmin,                                 \
    .sec = dsec,                                 \
    .system = dsystem,                          \
}




void ClockMode01_Create(void* param);
void ClockMode01_UpData(void* param);

#endif // CLOCK_MODE01_H


