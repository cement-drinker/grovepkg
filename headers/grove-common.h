#include    <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <unistd.h>
#include <sys/stat.h>

int setup(char maindir[], char worldfile[], char sources[])
{
    char pkgrootdir[100];                strcat(strcpy(pkgrootdir, maindir), "/pkg");
    char  worldfile[100];   strcat(strcpy(worldfile, pkgrootdir), "/data/worldfile");
    char sourcefile[100]; strcat(strcpy(sourcefile, pkgrootdir), "/data/sourcefile");
   
    char workdir[100]; strcat(strcpy(workdir, maindir), "/work/");
    char datadir[100]; strcat(strcpy(datadir, maindir), "/data/");
    char  srcdir[100]; strcat(strcpy(srcdir, maindir),  "/src/");
    int newitemsmade = 0;

    if ( access(maindir, F_OK) )
    {
        mkdir(maindir, 0744);
        newitemsmade++;

        mkdir(workdir, 0744);
        newitemsmade++;

        mkdir(datadir, 0744);
        newitemsmade++;

        mkdir(srcdir, 0744);
        newitemsmade++;
    } else if ( !access(maindir, F_OK) && access(workdir, F_OK) &&access(datadir, F_OK) && access(srcdir, F_OK) )
    {
        mkdir(workdir, 0744);
        newitemsmade++;

        mkdir(datadir, 0744);
        newitemsmade++;

        mkdir(srcdir, 0744);
        newitemsmade++;
    }

    if  ( access(worldfile, F_OK) )
    {
        fopen(worldfile, "w");
        newitemsmade++;
    }


    if  ( access(sources, F_OK) )
    {
        fopen(sources, "w");
        newitemsmade++;
    }

    printf("%s", workdir);

    }


    void usage(char tool[])
    {
        if(strcmp(tool, "setup"))
        {
            printf("GROVE-SETUP PKG TOOL\n");
            printf("usage: grove-setup [OPTIONS]\n");
            printf("[OPTIONS] can be any of '-v (verbose) -V (version) -M (maindir)\n");
        }
        printf("-------------\n");
        printf("version 0.1\n");
    }
