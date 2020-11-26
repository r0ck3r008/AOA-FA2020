#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

#include"algorithms/alg1.h"

using namespace algorithms::alg1;
using std::max;
using std::min;

int
topdown(vector<vector<int>> &mat, uint32_t i, uint32_t j, int h, vector<vector<int>> &cache)
{
        if(i>=mat.size() || j>=mat[i].size())
                return 0;

        if(mat[i][j]<h) {
                cache[i][j] = 0;
        } else if(cache[i][j]==-1) {
                cache[i][j] = min(topdown(mat, i+1, j, h, cache),
                                min(topdown(mat, i, j+1, h, cache),
                                        topdown(mat, i+1, j+1, h, cache))) + 1;
        }

        return cache[i][j];
}

void
algorithms::alg1::task1(vector<vector<int>> &mat, int h, int *ret)
{
        vector<vector<int>> cache(mat.size(), vector<int>(mat[0].size(), -1));
        int max_sz = 0;
        bool flag = false;
        for(uint32_t i=0; i<mat.size(); i++) {
                for(uint32_t j=0; j<mat[i].size(); j++) {
                        int tmp_max = topdown(mat, i, j, h, cache);
                        if(tmp_max > max_sz) {
                                max_sz = tmp_max;
                                flag=true;
                                ret[0] = i;
                                ret[1] = j;
                        }
                }
        }

        if(flag) {
                ret[2] = max_sz + ret[0] - 1;
                ret[3] = max_sz + ret[1] - 1;
        }
}

void
algorithms::alg1::task2(vector<vector<int>> &mat, int h, int *ret)
{
	int max_sz = 0;
        vector<vector<int>> dp(3, vector<int>(mat[0].size()+1, 0));
        for(uint32_t i=0; i<mat.size(); i++) {
                for(uint32_t j=0; j<mat[i].size(); j++) {
                        int new_i = i%2+1, new_j = j%2+1;
                        if(mat[i][j] >= h) {
                                dp[new_i][new_j] = 1 + min(dp[new_i-1][new_j],
                                                min(dp[new_i][new_j-1],
                                                dp[new_i-1][new_j-1]));
                                if(dp[new_i][new_j] > max_sz) {
                                        max_sz = dp[new_i][new_j];
                                        ret[0] = i;
                                        ret[1] = j;
                                }
                        } else {
                                dp[new_i][new_j] = 0;
                        }
                }
        }
}
