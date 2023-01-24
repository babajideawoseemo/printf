#include "main.h"

/**
* get_flag - turns on flag if _printf finds
* a flag modifier in the format string
* @s: flag specifier
* @f: pointer to the struct flags
*
* Return: 1 if a flag has been turned on, otherwise 0
*/

int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;

		case ' ':
			f->plus = 1;
			i = 1;
			break;

		case '#':
			f->plus = 1;
			i = 1;
			break;

	}

	return (i);
}
