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

int usage(char tool[], char args[], char options[], char version[])
{
    printf("GROVE PACKAGE MANAGER: %s\n", tool);
    printf("usage: %s %s\n", tool, args);
    printf("where [OPTIONS] can be either of %s\n", options);
    printf("--------------\n");
    printf("version: %s\n", version);
}

int addpkg(char pkg[], char prefix[], char source[], char comprfmt[]) 
{
    /* Unset Variables (passed to curl-easy-setopt) */


    /* Argument-Variables (the variable is equal to some operation done on the arguments given to addpkg) */
    char      tarfmt[FILENAME_MAX]; strcat(strcpy(tarfmt, ".tar."), comprfmt);
    char  prefdirpkg[FILENAME_MAX]; strcat(strcpy(prefdirpkg, prefix), "/usr/share/grove/work/"); 
    char     pkgfile[FILENAME_MAX]; strcat(strcpy(pkgfile, prefdirpkg), pkg);

    char    pkgwtfmt[FILENAME_MAX]; strcat(strcpy(pkgwtfmt, pkgfile), tarfmt);
    char         url[FILENAME_MAX]; strcat(strcpy(url, source), pkg); strcat(url, tarfmt);
    char         cmd[FILENAME_MAX]; strcat (strcpy(cmd, "tar -xvf "), pkgwtfmt);
                                    strcat(cmd, " -C ");
                                    strcat(cmd, prefdirpkg);
 
    
    download_pkg(pkgwtfmt, url);
    system(cmd);
    return 0;
    
}

int download_pkg(char file[], char url[])
{
    CURL *curl;
    FILE *fp;
 
    CURLcode res;
    
    curl = curl_easy_init();

    /* Run Curl*/
    if (curl) {
        fp = fopen(file,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}