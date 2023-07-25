#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

/* CREDIT HERE 

the download part of addpkg is from this stackoverflow post:
https://stackoverflow.com/a/1636415

everything else by me.

*/
int usage(char tool[], char args[], char options[], char version[])
{
    printf("GROVE PACKAGE MANAGER: %s\n", tool);
    printf("usage: %s %s\n", tool, args);
    printf("where [OPTIONS] can be either of %s\n", options);
    printf("--------------\n");
    printf("version: %s\n", version);
}
int addpkg(char pkg[], char prefix[], char source[], char comprfmt[]) {
    /* Unset Variables (passed to curl-easy-setopt) */
    CURL *curl;
    FILE *fp;
    CURLcode res;

    /* Argument-Variables (the variable is equal to some operation done on the arguments given to addpkg) */
    char      tarfmt[FILENAME_MAX]; strcat(strcpy(tarfmt, ".tar."), comprfmt);
    char  prefdirpkg[FILENAME_MAX]; strcat(strcpy(prefdirpkg, prefix), "/usr/share/grove/work/"); 
    char     pkgfile[FILENAME_MAX]; strcat(strcpy(pkgfile, prefdirpkg), pkg);

    char    pkgwtfmt[FILENAME_MAX]; strcat(strcpy(pkgwtfmt, pkgfile), tarfmt);
    char         url[FILENAME_MAX]; strcat(strcpy(url, source), pkg); strcat(url, tarfmt);
    char         cmd[FILENAME_MAX]; strcat (strcpy(cmd, "tar -xvf "), pkgwtfmt);
                                    strcat(cmd, " -C ");
                                    strcat(cmd, prefdirpkg);
 
    
    /* Late variable declarations and additions */
    
    curl = curl_easy_init();

    /* Run Curl*/
    if (curl) {
        fp = fopen(pkgwtfmt,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    system(cmd);
    return 0;
    
}
