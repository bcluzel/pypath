#ifndef DEBUG_H
#define DEBUG_H

#include "stdio.h"

#ifdef DEBUG
    #define eprintf(fmt, ...)    printf("Debug> ");printf(fmt , ##__VA_ARGS__)
#else
    #define eprintf(fmt, ...)
#endif
#endif