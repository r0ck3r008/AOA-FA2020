#include<iostream>
#include<string.h>
#include<unistd.h>
#include<errno.h>

static FILE *logfile = stdout;

int main(int argc, char **argv)
{
        if(argc<2) {
                fprintf(stderr, "[!]Usage: ./AlgoTowers <input_file> [<logfile_name>]\n");
                _exit(1);
        } else if(argc==3) {
                FILE *logf=NULL;
                if((logf=fopen(argv[2], "w")) == NULL) {
                        fprintf(stderr, "[-]Fopen: %s: %s\n", argv[2], strerror(errno));
                        _exit(1);
                }
                logfile=logf;
        }

        FILE *inf=NULL;
        if((inf=fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "[-]Fopen: %s: %s\n", argv[1], strerror(errno));
                _exit(1);
        }


        fclose(inf);
        fclose(logfile);
}
