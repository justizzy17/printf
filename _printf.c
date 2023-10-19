#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: is a character string
 * @...: number of arguments to be entered
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	char c_vag;
	char *string;
	int string_len;
	int character_count = 0;

	va_list printf;

	if (format == NULL)
		return (-1);

	va_start (printf, format);

	if (format != NULL)
	{
		while (*format)
		{
			if (*format == '%')
			{
				format++;

				if (*format == 'c')
				{
					c_vag = va_arg(printf, int);
					write(1, &c_vag, 1);
					character_count++;
				}

				else if (*format == 's')
				{
					for (string_len = 0; string[string_len] != '\0'; string_len++)
					{
					}
					string = va_arg(printf, char *);
					write (1, string, string_len);
					character_count += string_len;
				}
				else if (*format == '%')
				{
					write(1, "%", 1);
					character_count++;
				}
			}
		else
		{
			write(1, format, 1);
				character_count++;
		}
		format++;
	}
	va_end(printf);
	}
		return (character_count);
}
