/*
 *   @(#)  [MB] ec_exple_execle.c Version 1.2 du 20/06/07 - 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **envp)
{
     char            *_str1, *_str2, **_p, *_path;

     if (argc != 3) {
          fprintf(stderr, "Usage: %s str1 str2\n", argv[0]);
          exit(1);
     }

     for (_p = envp; *_p != 0; _p++) {
          printf("%s\n", *_p);
     }
     printf("\n");
     fflush(stdout);

     _str1          = argv[1];
     _str2          = argv[2];

     _path          = "./exple_execle_02";

     execle(_path, "exple_execle_02", _str1, _str2, (char *) 0, envp);
     fprintf(stderr, "%s: cannot execute \"%s\"\n", argv[0], _path);

     return 1;
}
