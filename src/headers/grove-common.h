#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

/* CREDIT HERE 

the download part of addpkg is from this stackoverflow post:
https://stackoverflow.com/a/1636415

everything else by me.

*/

int usage(char tool[], char args[], char options[], char version[]);

int download_pkg(char file[], char url[]);

int addpkg(char pkg[], char prefix[], char source[], char comprfmt[]);