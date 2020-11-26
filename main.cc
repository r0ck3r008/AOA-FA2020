#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

#include"algorithms/alg1.h"
#include"algorithms/alg2.h"
#include"algorithms/alg3.h"

using std::vector;
using std::cout;
using std::endl;
using namespace algorithms::alg2;

FILE *logfile = stdout;

void
input_tc(vector<vector<int>> &grid, int *height, FILE *f)
{
        char *line=NULL;
        size_t n=0;
        bool flag=true;
        int rows=1, cols;
        while(rows!=0) {
                getline(&line, &n, f);
                char buf[32000];
                strncpy(buf, line, strlen(line));
                if(flag) {
                        rows = strtol(strtok(buf, " "), NULL, 10);
                        cols = strtol(strtok(NULL, " "), NULL, 10);
                        *height = strtol(strtok(NULL, " "), NULL, 10);
                        flag=false;
                        vector<vector<int>> vec(rows, vector<int>(cols));
                        grid=vec;
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

void
printout(int *ret, int sz)
{
        for(int i=0; i<sz; i++){
                cout << ret[i];
                if(i!=sz-1)
                        cout << ",";
                else
                        cout << endl;
        }
}

void
task_runner(vector<vector<int>> &grid, int height)
{
        int ret_sq[2] = {0}, ret_rec[4] = {0};

        /* Task 1 */
        algorithms::alg1::task1(grid, height, ret_sq);
        printout(ret_sq, 2);

        /* Task 2 */
        algorithms::alg1::task2(grid, height, ret_sq);
        printout(ret_sq, 2);

        /* Task 3 */
        algorithms::alg2::task3(grid, height, ret_rec);
        printout(ret_rec, 4);

        /* Task 4 */
        algorithms::alg3::task4(grid, height, ret_rec);
        printout(ret_rec, 4);

        /* Task 5 */
        algorithms::alg3::task5(grid, height, ret_rec);
        printout(ret_rec, 4);
}

int
main(int argc, char **argv)
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

        task_runner(grid, height);

        fclose(inf);
        fclose(logfile);
}
