#include  <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "headers/grove-common.h"

int main(int argc, char *argv[])
{
    int opt;

    char ver[] = "grove-add v0.1";
    char args[] = "[OPTIONS] [PACKAGE]";
    char avopts[] = "-P (prefix), -h (help), -V (verbose), -v (version), -F (tar format), -U (url)";
    char *prefix = "";  
    char *format = "xz";
    char *url = "https://cdn.kernel.org/pub/linux/kernel/v6.x/";

    while((opt = getopt(argc, argv, ":P:U:F:hVv")) != -1) 
    {
        switch(opt)
        {
            case 'P':
                prefix = optarg;
                break;

            case 'F':
                format = optarg;
                break;

            case 'U':
                url = optarg;
                break;
            
            case 'V':
                printf("placeholder");
                break;
            
            case 'v':
                printf("%s\n", ver);
                return 0;
                break;

            case 'h':
                usage(argv[0], args, avopts, ver);
                return 0;
                break;
            
            case ':':
                fprintf(stderr, "\e[1;31merr\e[0m: no argument given to the option");
                usage(argv[0], args, avopts, ver);
                break;

            case '?':
                fprintf(stderr, "\e[1;31merr\e[0m: not a valid option");
                usage(argv[0], args, avopts, ver);
                break;
        }

    }

    addpkg("linux-6.4.3", prefix, url, format);
    
    free(format);
    free(url);
    free(prefix);

    return 0;

}