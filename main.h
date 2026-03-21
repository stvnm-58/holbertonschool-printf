#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


typedef struct spec
{
    char lettre;
    void (*fonction)(va_list);
}spec_t;


int _printf(const char *format, ...);

#endif
