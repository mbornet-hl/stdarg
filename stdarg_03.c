/*
 * Copyright (C) 2020, Martial Bornet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	@(#)	[MB] ec_stdarg_03.c	Version 1.2 du 20/06/13 - 
 */

#include <stdio.h>
#include <stdarg.h>

/* f() */
void f(int call_no, int n, ...)
{
	va_list		 _args;
	char			*_s, *_old_args, *_p;

	printf("===== CALL %d =====\n", call_no);

	printf("Address of call_no = %p\n", &call_no);
	printf("Address of n       = %p\n", &n);

	va_start(_args, n);
	_old_args		= (char *) &n;
	_p			= ((char **)(_old_args += sizeof(char *)))[-1];

	printf("_old_args          = %p\n", _old_args);
	printf("_p                 = %p\n", _p);
	if (n >= 1) {
		printf("_args              = %p\n", _args);
		_s			= va_arg(_args, char *);
		printf("param 1 = \"%s\"\n", _s);
	}
	if (n >= 2) {
		printf("_args              = %p\n", _args);
		_s			= va_arg(_args, char *);
		printf("param_2 = \"%s\"\n", _s);
	}
	if (n >= 3) {
		printf("_args              = %p\n", _args);
		_s			= va_arg(_args, char *);
		printf("param_3 = \"%s\"\n", _s);
	}

	va_end(_args);
	printf("\n");
}

/* main() */
int main()
{
	char			*_a = "A----",
				*_b = "BB---",
				*_c = "CCC--";

	f(1, 3, _a, _b, _c);
	f(2, 2, _a, _b);
	f(3, 1, _a);
	f(4, 3, _c, _b, _a);

	return 0;
}
