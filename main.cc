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
#include"timer/timer.h"

using std::vector;
using std::cout;
using std::endl;
using timer::Timer;
using namespace algorithms::alg2;

FILE *logfile = stdout;

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
        string comma = ",", eol = "\n";
        int ret[4] = {0};
        Timer t;

        /* Task 1 */
        t.start();
        algorithms::alg1::task1(grid, height, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 2 */
        t.start();
        algorithms::alg1::task2(grid, height, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 3 */
        t.start();
        algorithms::alg2::task3(grid, height, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 4 */
        t.start();
        algorithms::alg3::task4(grid, height, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 5 */
        t.start();
        algorithms::alg3::task5(grid, height, ret);
        t.stop(eol);
        printout(ret, 4);
}

void
execute(FILE *inf)
{
        char buf[32000] = {0};
        char *line=NULL;
        size_t n=0;
        getline(&line, &n, inf);
        strncpy(buf, line, strlen(line));
        int rows = strtol(strtok(buf, " "), NULL, 10);
        int cols = strtol(strtok(NULL, " "), NULL, 10);
        int height = strtol(strtok(NULL, " "), NULL, 10);
        int val;
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++) {
                free(line);
                line=NULL;
                n=0;
                explicit_bzero(buf, sizeof(char) * 32000);

                getline(&line, &n, inf);
                strncpy(buf, line, strlen(line));

                val = strtol(strtok(buf, " "), NULL, 10);
                grid[i][0] = (val >= height) ? (1) : (0);
                for(int j=1; j<cols; j++) {
                        val = strtol(strtok(NULL, " "), NULL, 10);
                        grid[i][j] = (val >= height) ? (1) : (0);
                }
        }

        task_runner(grid, height);
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
        execute(inf);

        fclose(inf);
        fclose(logfile);
}
