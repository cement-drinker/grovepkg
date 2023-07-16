#include <stdio.h>
#include <string.h>

#include "headers/grove-common.h"

int main(int argc, char* argv[])
{
    char ver[] = "grove-add v0.1";
    char args[] = "[OPTIONS] [PACKAGE]";
    char opts[] = "-P (prefix), -h (help), -V (verbose), -v (version)";
    char *prefix = "";

    for(int i=0; i<argc; ++i) 
    {
        if( !strcmp(argv[i], "-P") && argc==i+1 )
        {
            printf("\e[1;31merr\e[0m: -M must have a prefix as the next argument\n");
            return 0;
        }

        if( !strcmp(argv[i], "-P") ) 
        {
            prefix = argv[i+1];
        } else if( !strcmp(argv[i], "-h") ) 
        {
            usage("grove-add", args, opts, ver);
            return 0;
        } else if( !strcmp(argv[i], "-v"))
        {
            printf("%s\n", ver);
            return 0;
        }

    }

    addpkg("linux-6.4.3.tar.xz", prefix, "https://cdn.kernel.org/pub/linux/kernel/v6.x/");
    
    return 0;

}