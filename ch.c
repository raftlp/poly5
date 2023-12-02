/**
 * \file   ch.c
 * \author Oliver Stecklina <oliver.stecklina@th-luebeck.de>
 * \date   16.11.2023
 *
 * \brief  OS multiplexer to getch function.
 */

#include "ch.h"

#ifdef _WIN32

/*
 * Windows implementation, using getch() from conio.h
 */

#include <conio.h>

char ch_get()
{
	return getch();
}

#else

/*
 * Unix implementation, read char from stdin
 */

#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <errno.h>

char ch_get(void)
{
    char buf = 0;
    struct termios old = {0};

    fflush(stdout);
    if (tcgetattr(0, &old) < 0) {
    	buf = -errno;
    } else {
		old.c_lflag &= ~ICANON;
		old.c_lflag &= ~ECHO;
		old.c_cc[VMIN] = 1;
		old.c_cc[VTIME] = 0;

		if (tcsetattr(0, TCSANOW, &old) < 0) {
			buf = -errno;
		} else {
			if (read(0, &buf, 1) < 0) {
				buf = -errno;
			} else {
				old.c_lflag |= ICANON;
				old.c_lflag |= ECHO;

				if (tcsetattr(0, TCSADRAIN, &old) < 0) {
					buf = -errno;
				}
			}
		}
    }

    return buf;
}

#endif
