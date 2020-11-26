#include<iostream>
#include<algorithm>

#include"algorithms/alg1.h"

using std::min;
using namespace algorithms::alg1;

void
algorithms::alg1::task1(vector<vector<int>> &mat, int h, int *ret)
{

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
