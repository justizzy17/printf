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
	char *string, str_num[12];
	int string_len = 0;
	int num, temp, digit, character_count = 0;

	va_list printf;

	va_start (printf, format);

	if (format == NULL)
		return (-1);

	else
	{
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				if (*format == '\0')
					break;

				if (*format == 'c')
				{
					c_vag = va_arg(printf, int);
					write(1, &c_vag, 1);
					character_count++;
				}

				else if (*format == 's')
				{
					string = va_arg(printf, char *);
					while (string[string_len] != '\0')
							string_len++;
					write (1, string, string_len);
					character_count += string_len;
				}
				else if (*format == '%')
				{
					write(1, format, 1);
					character_count++;
				}
				else if (*format == 'd' || *format == 'i')
				{
					num = va_arg(printf, int);
					temp = num;
					digit = 0;

					while (temp != '\0')
					{
						temp = temp / 10;
						digit++;
					}
					str_num[digit] = '\0';
					while (num != 0)
					{
						str_num[--digit] = '0' + (num % 10);
						num /= 10;
					}
					write(1, str_num, digit);
					character_count += digit;
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
