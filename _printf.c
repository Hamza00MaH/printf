#include"main.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>

/**
* _printf - our printf functionnn
* @format: string contain specifier form
* Return: num of char printed
*/

int _printf(const char *format, ...)
{
int num_prt_char = 0, num = 0;
char *str;
va_list arg;
va_start(arg, format);
while (*format)
{
if (*format == '%')
{ format++;
switch (*format)
{ case 'c':
num = va_arg(arg, int);
write(STDOUT_FILENO, &num, 1);
num_prt_char++;
break;
case 's':
str = va_arg(arg, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
write(STDOUT_FILENO, str, 1);
str++;
num_prt_char++; }
break;
case '%':
write(STDOUT_FILENO, "%", 1);
num_prt_char++;
break;
default:
write(STDOUT_FILENO, "%", 1);
write(STDOUT_FILENO, &(*format), 1);
num_prt_char += 2;
break; }}
else
{
write(STDOUT_FILENO, &(*format), 1);
num_prt_char++; }
format++; }
va_end(arg);
return (num_prt_char); }
