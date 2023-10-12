#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its paramters.
 * @n: The number of paramters passed to the function.
 * @...: A variable number of paramters to calculate the sum of.
 *
 * Return: SAM
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int t, SAM = 0;

	va_start(ap, n);

	for (t = 0; t < n; t++)
		SAM += va_arg(ap, int);

	va_end(ap);

	return (SAM);
}

