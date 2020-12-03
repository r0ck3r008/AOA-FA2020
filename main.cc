#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

#include"alg1.h"
#include"alg2.h"
#include"alg3.h"
#include"timer.h"

using std::vector;
using std::cout;
using std::endl;
using timer::Timer;

FILE *logfile = stdout;

/*
 * printout prints the returned co-ordinates array.
 *
 * It inputs the pointer to the pre-allocated int array with
 * its size as second element. This returns nothing.
 */
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

/*
 * task_runner runs all the 4 tasks and handles the timer operations.
 *
 * It inputs the 2D array in form of reference to a vector of vectors.
 * This returns nothing.
 */
void
task_runner(vector<vector<int>> &grid)
{
        string comma = ",", eol = "\n";
        int ret[4] = {0};
        Timer t;

        /* Task 1 */
        t.start();
        algorithms::alg1::task1(grid, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 2 */
        t.start();
        algorithms::alg1::task2(grid, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 3 */
        t.start();
        algorithms::alg2::task3(grid, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 4 */
        t.start();
        algorithms::alg3::task4(grid, ret);
        t.stop(comma);
        printout(ret, 4);

        /* Task 5 */
        t.start();
        algorithms::alg3::task5(grid, ret);
        t.stop(eol);
        printout(ret, 4);
}

/*
 * execute reads the input test case file and turns the provided 2D matrix
 * into binary matrix by comparing each element to the height in the file.
 * It then calls the task_runner and passes the 2D matrix to it.
 *
 * It inputs a pointer to the opened file pointer.
 */
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

        task_runner(grid);
}

/*
 * main function serves as the entry point to the programs and checks to see
 * if the provided arguments are sane. It then opens the input file and logfile
 * (if necessary) and passes all of it to execute function. In the end it closes
 * the files it opened.
 */
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
