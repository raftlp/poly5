 /**
 * \file   cio.c
 * \author Oliver Stecklina <oliver.stecklina@th-luebeck.de>
 * \date   16.11.2023
 *
 * \brief  Console IO functions.
 */

#include <stdio.h>

#include "ch.h"
#include "cio.h"

int cio_get_number(const int echo, const char delimiter)
{
	int stop, num, plcs;

	stop = 0;
	num = 0;
	plcs = 0;

	while (plcs < 9 && 0 == stop) {
		int c;

		c = ch_get();
		if ('\r' == c || '\n' == c) {
			stop = 1;
		} else {
			if (CIO_ECHO_ON == echo) {
				printf("%c", c);
			}

			if (delimiter == c) {
				stop = 1;
			} else {
				if ('0' <= c && c <= '9') {
					num *= 10;
					num += c - '0';

					plcs++;
				} else {
					num = 0 - c;
					stop = 1;
				}
			}
		}
	}

	return num;
}
