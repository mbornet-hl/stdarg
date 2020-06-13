/*
 *   @(#)  [MB] ec_stdarg_08.c Version 1.2 du 20/06/07 - 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>

// void f(int i, char *msg1, ..., char *msg2, ...)

void prt(int i, const char *args, ...)
{
     va_list              _args;
     static const char   *_func;
     const char          *_format;
     char                 _date[32];
     struct timeval       _time;
     struct tm           *_tm;

     if (i == 0) {
          _func     = args;
     }
     else {
          if (gettimeofday(&_time, 0) != 0) {
               perror("gettimeofday");
               exit(1);
          }
          _tm       = localtime(&_time.tv_sec);
          sprintf(_date, "%4d-%02d-%02d %02d:%02d:%02d.%06d",
                  1900 + _tm->tm_year, _tm->tm_mon + 1, _tm->tm_mday,
                  _tm->tm_hour, _tm->tm_min, _tm->tm_sec,
                  (int) _time.tv_usec);
          _format   = args;
          va_start(_args, args);

          printf("%s %s() : %d. ", _date, _func, i);

          vprintf(_format, _args);
          va_end(_args);
     }
}

void f(int i, char *msg1, ...)
{
     va_list              _args;
     char                *_p, *_msg2;

     va_start(_args, msg1);

     prt(0, __func__);
     prt(i, "Execution numero %d\n", i);
     prt(i, "%s\n", msg1);

     for ( ; (_p = va_arg(_args, char *)) != NULL; ) {
          prt(i, "LISTE 1 : [%s]\n", _p);
     }
     prt(i, "Fin de la premiere liste.\n\n");

     _msg2     = va_arg(_args, char *);
     prt(i, "%s\n", _msg2);

     for ( ; (_p = va_arg(_args, char *)) != NULL; ) {
          prt(i, "LISTE 2 : [%s]\n", _p);
     }
     prt(i, "Fin de la deuxieme liste.\n");
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
