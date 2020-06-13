/*
 *	@(#)	[MB] ec_stdarg_06.c	Version 1.1 du 20/06/07 - 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

// void f(int i, char *msg1, ..., char *msg2, ...)

void f(int i, char *msg1, ...)
{
     va_list              _args;
     char                *_p, *_msg2;

     va_start(_args, msg1);

     printf("%s() : Execution numero %d\n", __func__, i);
     printf("%s() : %s\n", __func__, msg1);

     for ( ; (_p = va_arg(_args, char *)) != NULL; ) {
          printf("%s() : LISTE 1 : [%s]\n", __func__, _p);
     }
     printf("%s() : Fin de la premiere liste.\n\n", __func__);

     _msg2     = va_arg(_args, char *);
     printf("%s() : %s\n", __func__, _msg2);

     for ( ; (_p = va_arg(_args, char *)) != NULL; ) {
          printf("%s() : LISTE 2 : [%s]\n", __func__, _p);
     }
     printf("%s() : Fin de la deuxieme liste.\n", __func__);
     va_end(_args);
     printf("\n");
}

int main()
{
     f(1, "Premiere liste :", "A", "B", "C", NULL,
          "Deuxieme liste :", "X", "Y", "Z", NULL);

     f(2, "Premiere liste :", "a", "b", "c", "d", "e", NULL,
          "Deuxieme liste :", "x", "y", "z", "1234", "END", NULL);

     return 0;
}
