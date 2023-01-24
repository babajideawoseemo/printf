#include "main.h"

/**
* get_print - selects the right print func based onthe
* specifier passed to _printf
* @s: specifier
* Description: loops through the array of function pointers
* Return: a pointer to the matching print f unc
*/

int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};

	int funcs = 14, i;

	for (i = 0; i < funcs; i++)
	{
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	}

	return (NULL);
}

