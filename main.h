#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct spec
{
	char lettre;
	int (*fonction)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_c(va_list arg);
int print_s(va_list arg);

#endif
