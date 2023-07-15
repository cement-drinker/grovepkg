#include <stdio.h>
#include <string.h>

#include "headers/grove-common.h"

int main(int argc, char* argv[])
{
    char *maindir = "";

    for(int i=0; i<argc; ++i) 
    {
        if( !strcmp(argv[i], "-M") && argc==i+1 )
        {
            printf("\e[1;31merr\e[0m: -M must have a maindir as the next argument");
            return 0;
        }

        if( !strcmp(argv[i], "-M") ) 
        {
            maindir = argv[i+1];
        }
    }

    addpkg("linux-6.4.3.tar.xz", maindir, "https://cdn.kernel.org/pub/linux/kernel/v6.x/");
    
    return 0;

}