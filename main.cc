#include<iostream>
#include<string.h>
#include<unistd.h>
#include<errno.h>

const FILE *logfile;

int main(int argc, char **argv)
{
        if(argc!=2) {
                fprintf(stderr, "[!]Usage: ./AlgoTowers <logfile_name>\n");
                _exit(1);
        }

        FILE *f=NULL;
        if((f=fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "[-]Error in opening: %s: %s\n", argv[1], strerror(errno));
                _exit(1);
        }

        logfile = f;

        fclose(f);
}
