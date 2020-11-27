#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

#include"algorithms/alg1.h"

using namespace algorithms::alg1;
using std::max;
using std::min;

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
