/*
  
    /----------------------------------------------------------/
   /  No License. This may be reconsidered later.             /
  /  For Now, this program is in the public domain           /
 /  This is because this program is currently insignificant./
/----------------------------------------------------------/


*/


/* system headers */
#include    <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <unistd.h>


/* custom headers */
#include "headers/grove-common.h"

int main(int argc, char *argv[]){
    printf("%i", argc);


    char       maindir[]= "";
    
    for(int i=0; i<argc; i++) {
        if( !strcmp(argv[i], "help") )
        {
            usage("setup");
            return 0;
        }
        if( !strcmp(argv[i], "-M"))
        {
            maindir = argv[i + 1];
        }
        if( argc > 2 ) {
            return 0;
        }
    }
    setup(maindir, worldfile, sourcefile);
    return 0;
}
