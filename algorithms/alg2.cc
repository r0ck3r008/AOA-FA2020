#include<iostream>

#include"algorithms/alg2.h"

using namespace algorithms::alg2;

void
task3(vector<vector<int>> &mat, int h, pair<pair<int, int>, pair<int, int>> &ret)
{
	int max_sz = 0;
        int ret_pairs[4];
	for(uint32_t i = 0; i < mat.size(); i++) {
		int flag = 1;
		for(uint32_t j = i; j < mat[i].size(); j++) {
                        uint32_t k = j, l = i;
			for(; k < mat.size() && flag; k++) {
				for(; i < mat[i].size() && flag; l++) {
					if(mat[k][j] < h)
						flag = 0;
				}
			}
			if(flag) {
				int sz = (i + 1) * (j + 1);
				if (max_sz < sz) {
					max_sz = sz;
                                        ret_pairs[0] = k;
                                        ret_pairs[1] = l;
                                        ret_pairs[2] = i;
                                        ret_pairs[3] = j;
                                }
			}
		}
	}

        ret.first = pair<int, int>(ret_pairs[0], ret_pairs[1]);
        ret.second = pair<int, int>(ret_pairs[2], ret_pairs[3]);
}
