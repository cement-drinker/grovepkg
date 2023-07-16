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
int addpkg(char pkg[], char prefix[], char source[]) {
    /* Unset Variables (passed to curl-easy-setopt) */
    CURL *curl;
    FILE *fp;
    CURLcode res;

    /* Argument-Variables (the variable is equal to some operation done on the arguments given to addpkg) */
    char     url[FILENAME_MAX];                          strcat(strcpy(url, source), pkg);
    char pkgdest[FILENAME_MAX]; strcat(strcpy(pkgdest, prefix), "/usr/share/grove/work/");
    
    /* Late variable declarations and additions */
    pkgdest; strcat(pkgdest,pkg);
    curl = curl_easy_init();

    /* Run Curl*/
    if (curl) {
        fp = fopen(pkgdest,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}
