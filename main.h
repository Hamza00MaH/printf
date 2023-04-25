#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int handle_c_or_s(int i, va_list arg, int *num_prt_char);
char *int_to_base(int num, int base);
int handle_d_or_i(int i, va_list arg, int *num_prt_char);
int handle_binary(int i, va_list arg, int *num_prt_char);


#endif /*MAIN_H*/
