#include "main.h"
/** author for this code : MahmoudMetwalli && AhMeDMaGDY28*/
/**/
/**
 * print_bi - Print a binary number.
 * @args: The va_list containing the binary number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_bi(va_list args)
{
	unsigned int m = va_arg(args, unsigned int);
	char *s = conv(m, 2, 0);
	int len = 0;

	return (len += print_no(s));
}
/**/
/**
 * print_octs - Print an octal number.
 * @args: The va_list containing the octal number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_octs(va_list args)
{
	unsigned int h;
	int len = 0;
	char *s;

	h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 8, 0);
	return (len += print_no(s));
}
/**/
/**
 * print_low_hexes - Print a lowercase hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_low_hexes(va_list args)
{
	unsigned int h;
	int len = 0;
	char *s;

	h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 16, 1);
	return (len += print_no(s));
}
/**/

/**
 * print_up_hexes - Print an uppercase hexadecimal number.
 * @args: The va_list containing the hexadecimal number to print.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - Returns the number of characters printed.
 */
int print_up_hexes(va_list args)
{
	unsigned int h;
	int len = 0;
	char *s;

	h = (unsigned int)va_arg(args, unsigned int);
	s = conv(h, 16, 0);
	return (len += print_no(s));
}
/**/

/**
 * print_stringhex - Print a string with non-printabl
 * characters replaced by hexadecimal.
 * @args: A va_list representing the variable arguments.
 *
 * Description:
 * This function takes a string as an argument and prints it.
 *  If the string contains
 * non-printable characters, it replaces each such
 * character with its hexadecimal representation
 * preceded by '\\x'. The function returns
 * the total number of characters printed.
 *
 * @args: A va_list representing the variable arguments.
 *  It is expected to contain a char* argument.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 *
 * Return:
 * - The total number of characters printed.
 * - Returns -1 on error.
 */
int print_stringhex(va_list args)
{
	char *s = va_arg(args, char *);
	char *hexes;
	int len = 0;

	if (!s)
		return (_puts("(null)"));

	for (; *s; s++)
	{
		if ((*s > 0 && *s < MIN_PRINTABLE_ASCII) || *s >= MAX_PRINTABLE_ASCII)
		{
			len += _putchar('\\');
			len += _putchar('x');
			hexes = conv(*s, 16, 0);

			if (!hexes)
				return (-1);
			if (!hexes[1])
				len += _putchar('0');

			len += _puts(hexes);
			free(hexes);
		}
		else
		{
			len += _putchar(*s);
		}
	}
	return (len);
}
