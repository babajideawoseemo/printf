#include "main.h"

/**
* print_bigS - Non printable characters
* (0 < ASCII value < 32 or >= 127) are printed
* this way; \x, followed by ASCII value in hex
* (uppercase - always 2 characters)
* @l: va_list argument pointer
* @f: pointer to struct flag that determines
* if a flag is passed to _printf
* Return: num of char printed
*/

int print_bigS(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			puts('\\x');
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
* print_rev - prints a string in reverse
* @l: argument from _printf
* @f: pointer to struct flag that determines if a flag
* is passed to _printf
* Return: length of printed string
*/

int print_rev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";
	while (s[i])
		i++;
	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);
	return (i);

}

/**
* print_percent - prints a percent sign
* @l: var arg pointer
* @f: pointer to struct flag
* Return: number of char printed
*/

int print_percent(va_list, flag_t *f)
{
	(void)l;
	(void)f;

	return (_putchar('%'));
}

/**
* rot13 - prints a string using rot13
* @l: var arg pointer
* @f: pointer to struct flag
* Return: length of printed string
*/

int print_rot13(va_list l, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}
	return (j);
}
