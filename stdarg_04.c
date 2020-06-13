/*
 *	@(#)	[Zen] ec_stdarg_04.c	Version 1.1 du 20/06/13 - 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **envp)
{
	char				**_p, *_pref1, *_pref2;
	int				  _lg1, _lg2;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s prefix1 prefix2\n", argv[0]);
		exit(1);
	}

	_pref1			= argv[1];
	_pref2			= argv[2];

	_lg1				= strlen(_pref1);
	_lg2				= strlen(_pref2);

	for (_p = envp; *_p != 0; _p++) {
		if (!strncmp(*_p, _pref1, _lg1)) {
			printf("%-*s : [%s]\n", _lg1, _pref1, *_p);
		}
	}

	for (_p = envp; *_p != 0; _p++) {
		if (!strncmp(*_p, _pref2, _lg2)) {
			printf("%-*s : [%s]\n", _lg2, _pref2, *_p);
		}
	}

	return 0;
}
