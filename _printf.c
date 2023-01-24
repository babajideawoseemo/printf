#include "main.h"

/**
* _printf - prints a format string with specified
* arguments of different types
* @format: format string. would usu contain specified
* identifiers
* Description: calls get_print_func to return the
* function needed to print the type specified by the identifier
* Return: num of characters printed to stdout
*/

int _printf(const char *format, ...)
{
	va_list ap;
	const char *p;
	int (*pfunc)(va_list, flags_t *);
	int i, num_char = 0;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				num_char += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			num_char += (pfunc)
				? pfunc(ap, &flags)
				: printf("%%%c", *p);
		}
		else
			num_char += _putchar(*p);
	}
	_putchar(-1);
	va_end(ap);
	return (num_char);

}
