#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

using std::vector;

FILE *logfile = stdout;

void input_tc(vector<vector<int>> &grid, int *height, FILE *f)
{
        char *line=NULL;
        size_t n=0;
        bool flag=true;
        int rows=1, cols;
        while(rows!=0) {
                getline(&line, &n, f);
                if(flag) {
                        rows = strtol(strtok(buf, " "), NULL, 10);
                        cols = strtol(strtok(NULL, " "), NULL, 10);
                        *height = strtol(strtok(NULL, " "), NULL, 10);
                        flag=false;
                } else {
                        vector<int> column(cols);
                        column.push_back(strtol(strtok(buf, " "), NULL, 10));
                        for(int i=0; i<cols-1; i++)
                                column.push_back(strtol(strtok(NULL, " "), NULL, 10));
                        grid.push_back(column);
                        rows--;
                }
                free(line);
                line=NULL;
                n=0;
        }
}

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

        vector<vector<int>> grid;
        int height=0;
        input_tc(grid, &height, inf);

        fclose(inf);
        fclose(logfile);
}
