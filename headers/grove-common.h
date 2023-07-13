#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int addpkg(char pkg[], char prefix[], char[] source) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url; strcat(strcpy(url, source), pkg);
    char outfilename[FILENAME_MAX]; strcat(strcpy(outfilename, prefix), "/usr/share/grove/work/");
    outfilename; strcpy(outfilename,pkg)
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}
