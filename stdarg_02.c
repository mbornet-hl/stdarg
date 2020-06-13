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
 *   @(#)  [MB] ec_stdarg_02.c Version 1.3 du 20/06/13 - 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "stdarg_defs.h"

/* display() */
void display(int *types, ...)
{
     va_list              _args;
     int                  _i8, _i16;
     long                 _i32;
     long long            _i64;
     unsigned int         _u8, _u16;
     unsigned long        _u32;
     unsigned long long   _u64;
     double               _f;
     double               _d;
     char                *_s;
     int                 *_p, _sz = 8, _c;

     va_start(_args, types);

     for (_p = types; *_p != XX_END; _p++) {
          switch (*_p) {

          case XX_INT8:
               _i8            = va_arg(_args, int);
               printf("%-*s : %10d\n", _sz, "INT8", _i8);
               break;

          case XX_INT16:
               _i16           = va_arg(_args, int);
               printf("%-*s : %10d\n", _sz, "INT16", _i16);
               break;

          case XX_INT32:
               _i32           = va_arg(_args, long);
               printf("%-*s : %10ld\n", _sz, "INT32", _i32);
               break;

          case XX_INT64:
               _i64           = va_arg(_args, long long);
               printf("%-*s : %10lld\n", _sz, "INT64", _i64);
               break;

          case XX_UINT8:
               _u8            = va_arg(_args, unsigned int);
               printf("%-*s : %10u\n", _sz, "UINT8", _u8);
               break;

          case XX_UINT16:
               _u16           = va_arg(_args, unsigned int);
               printf("%-*s : %10u\n", _sz, "UINT16", _u16);
               break;

          case XX_UINT32:
               _u32           = va_arg(_args, unsigned long);
               printf("%-*s : %10lu\n", _sz, "UINT32", _u32);
               break;

          case XX_UINT64:
               _u64           = va_arg(_args, unsigned long long);
               printf("%-*s : %10llu\n", _sz, "UINT64", _u64);
               break;

          case XX_FLOAT:
               _f             = va_arg(_args, double);
               printf("%-*s : %10.8f\n", _sz, "FLOAT", _f);
               break;

          case XX_DOUBLE:
               _d             = va_arg(_args, double);
               printf("%-*s : %15.13g\n", _sz, "DOUBLE", _d);
               break;

          case XX_CHAR:
               _c             = va_arg(_args, int);
               printf("%-*s : %c\n", _sz, "CHAR", _c);
               break;

          case XX_STRING:
               _s             = va_arg(_args, char *);
               printf("%-*s : %s\n", _sz, "STRING", _s);
               break;

          default:
               printf("Type %d unknown !\n", *_p);
               exit(0);
          }
     }

     va_end(_args);
     printf("\n");
}

/* main() */
int main()
{
     int                  _types[16], _i, _i8, _i16;
     long                 _i64;
     char                *_str, _ch;
     float                _pi;
     double               _e;

     _i8                 = 255;
     _i16                = -10000;
     _i64                = 1234567890;
     _str                = "ABCDE";
     _ch                 = 'Z';
     _pi                 = 3.1415926535;
     _e                  = 2.718281828459045235360287;

     _i                  = 0;
     _types[_i++]        = XX_INT64;
     _types[_i++]        = XX_STRING;
     _types[_i++]        = XX_CHAR;
     _types[_i++]        = XX_END;
     display(_types, _i64, _str, _ch);

     _i                  = 0;
     _types[_i++]        = XX_INT16;
     _types[_i++]        = XX_INT8;
     _types[_i++]        = XX_END;
     display(_types, _i16, _i8);

     _i                  = 0;
     _types[_i++]        = XX_FLOAT;
     _types[_i++]        = XX_DOUBLE;
     _types[_i++]        = XX_END;
     display(_types, _pi, _e);

     return 0;
}
