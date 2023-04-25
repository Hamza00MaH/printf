#include "main.h"

/*****************************************************************************/

/** THE CONVER-TCHER **/

/*****************************************************************************/


/**
* int_to_base - Convert-integer-to-string
* @num: int to convert
* @base: base-wich-convert-int-to
* Return: pointer to a str representing the converted int
*/

char *int_to_base(int num, int base)
{
static char buf[33] = {0};
const char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
int i = 30;
if (num == 0)
{
buf[i--] = '0';
}
else
{
int sign = (num < 0) ? -1 : 1;
num *= sign;
while (num)
{
buf[i--] = digits[num % base];
num /= base;
}
if (sign == -1)
{
buf[i--] = '-';
}
}
return (&buf[i + 1]);
}


/***************************************************************************/

/**char and strings**/

/*****************************************************************************/


/**
*handle_c_or_s - our function
*@i: index's-specifier-in-format-str
*@arg: arguments of specifer
*@num_prt_char: pointer-to-count-printed-char
*Return:num of char printed
*/

int handle_c_or_s(int i, va_list arg, int *num_prt_char)
{
int c;
char *str;
if (i == 'c')
{
c = va_arg(arg, int);
num_prt_char += write(STDOUT_FILENO, &c, 1);
}
else if (i == 's')
{
str = va_arg(arg, char*);
if (str == NULL)
{
str = "(null)";
}
*num_prt_char += write(STDOUT_FILENO, str, strlen(str));
}
return (0);
}


/*****************************************************************************/

/** Integers **/

/*****************************************************************************/


/**
* handle_d_or_i - our function
*@i: index's-specifier-in-format-str
*@arg: arguments of specifer
*@num_prt_char: pointer-to-count-printed-char
*Return:num of char printed
*/

int handle_d_or_i(int i, va_list arg, int *num_prt_char)
{
char *str;
int num;
if (i == 'd' || i == 'i')
{
num = va_arg(arg, int);
str = int_to_base(num, 10);
*num_prt_char += write(STDOUT_FILENO, str, strlen(str));
}
else
{
return (-1);
}
return (0);
}


/****************************************************************************/

/** Binary **/

/****************************************************************************/


/**
* handle_binary - our function
*@i: index's-specifier-in-format-str
*@arg: arguments of specifer
*@num_prt_char: pointer-to-count-printed-char
*Return:num of char printed
*/

int handle_binary(int i, va_list arg, int *num_prt_char)
{
char *str;
int num;
if (i == 'b')
{
num = va_arg(arg, int);
str = int_to_base(num, 2);
*num_prt_char += write(STDOUT_FILENO, str, strlen(str));
}
else
{
return (-1);
}
return (0);
}


/***********************************************************************/
/**********************************************************************/

/****************************************************/

/**                   THE PRINTF                  **/

/***************************************************/

/***************************************************************************/
/****************************************************************************/
/**
 * _printf - our printf main function
 * @format: string containing format specifier
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
va_list arg;
int num_prt_char = 0;
va_start(arg, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'd':
case 'i':
handle_d_or_i(*format, arg, &num_prt_char);
break;
case 'c':
case 's':
handle_c_or_s(*format, arg, &num_prt_char);
break;
case '%':
write(STDOUT_FILENO, "%", 1);
num_prt_char++;
break;
case 'b':
handle_binary(*format, arg, &num_prt_char);
break;
default:
write(STDOUT_FILENO, "%", 1);
write(STDOUT_FILENO, &(*format), 1);
num_prt_char += 2;
break;
}}
else
{
write(STDOUT_FILENO, &(*format), 1);
num_prt_char++;
} format++;
}
va_end(arg);
return (num_prt_char);
}
