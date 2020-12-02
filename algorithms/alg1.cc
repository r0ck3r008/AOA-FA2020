#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

#include"algorithms/alg1.h"

using namespace algorithms::alg1;
using std::max;
using std::min;

/*
 * topdown is a helper function for `task1'. For each (i, j) where 0 <= i < rows
 * and 0 <= j < cols, it recursively calculates whether bottom, right or diagonally right element
 * is 1. This caches the calculated element results per recursion to save calculating them again
 * in the future.
 *
 * This takes a reference to the grid, current (i, j) as well as the reference to the `cache' vector
 * as input and returns the length of the side square of 1 which has its top left corner as (i, j).
 */
int
topdown(vector<vector<int>> &mat, uint32_t i, uint32_t j, vector<vector<int>> &cache)
{
        if(i>=mat.size() || j>=mat[i].size())
                return 0;

        if(!mat[i][j]) {
                cache[i][j] = 0;
        } else if(cache[i][j]==-1) {
                cache[i][j] = min(topdown(mat, i+1, j, cache),
                                min(topdown(mat, i, j+1, cache),
                                        topdown(mat, i+1, j+1, cache))) + 1;
        }

        return cache[i][j];
}

/*
 * `task1' is the topdown implementation of the dynamic programming algorithm to find the
 * largest square of 1s in the given 2D matrix. It iterates over all the elements in the matrix
 * and finds for each of them the width of the largest square of 1s with that element at top left
 * corner. It is accomplished by the helper function `topdown'. The largest of those scares is
 * what is selected in the end and its top right and bottom left co-ordinates are calculated.
 *
 * This inputs the 2D matrix in the form of a reference to a vector of vectors along with a
 * pointer to int array of size 4 (pre-allocated) to store the 4 co-ordinates. It returns nothing.
 */
void
algorithms::alg1::task1(vector<vector<int>> &mat, int *ret)
{
        vector<vector<int>> cache(mat.size(), vector<int>(mat[0].size(), -1));
        int max_sz = 0;
        for(uint32_t i=0; i<mat.size(); i++) {
                for(uint32_t j=0; j<mat[i].size(); j++) {
                        int tmp_max = topdown(mat, i, j, cache);
                        if(tmp_max > max_sz) {
                                max_sz = tmp_max;
                                ret[0] = i;
                                ret[1] = j;
                        }
                }
        }

        if(max_sz) {
                ret[2] = max_sz + ret[0] - 1;
                ret[3] = max_sz + ret[1] - 1;
        }
}

/*
 * `task2' is the bottom up implementation of the `alg1', i.e., finding the largest square of 1s
 * in a given binary 2D matrix. It accomplishes that by iterating over each element of the matrix
 * and calculating the largest square with that element as its bottom right corner. It then takes
 * the maximum of those squares' widths and selects that square as the final answer.
 *
 * It inputs the 2D matrix in the form of a reference to a vector of vectors along with a pointer
 * to a pre-allocated int array of size 4. The int array is used to return the 4 co-ordinates while
 * the subroutine actually returns nothing.
 */
void
algorithms::alg1::task2(vector<vector<int>> &mat, int *ret)
{
	int max_sz = 0;
        vector<vector<int>> dp(2, vector<int>(mat[0].size()+1, 0));
        for(uint32_t i=0; i<mat.size(); i++) {
                for(uint32_t j=0; j<mat[i].size(); j++) {
                        int new_i = i%2, new_j = j+1;
                        if(mat[i][j]) {
                                int offset = -1;
                                if(new_i == 0)
                                        offset = 1;
                                dp[new_i][new_j] = 1 + min(dp[new_i+offset][new_j],
                                                        min(dp[new_i][new_j-1],
                                                                dp[new_i+offset][new_j-1]));
                                if(dp[new_i][new_j] > max_sz) {
                                        max_sz = dp[new_i][new_j];
                                        ret[2] = i;
                                        ret[3] = j;
                                }
                        } else {
                                dp[new_i][new_j] = 0;
                        }
                }
        }

        if(max_sz) {
                ret[0] = ret[2] - max_sz + 1;
                ret[1] = ret[3] - max_sz + 1;
        }
}
