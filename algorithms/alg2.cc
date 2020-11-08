#include<iostream>

#include"algorithms/alg2.h"

using namespace algorithms::alg2;

int
run(vector<vector<int>> &mat, int h)
{
	int max_sz = 0;
	for(int i = 0; i < mat.size(); i++) {
		int flag = 1;
		for(int j = i; j < mat[i].size(); j++) {
			for(int k = j; k < mat.size() && flag; k++) {
				for(int l = i; i < mat[i].size() && flag; l++) {
					if(mat[k][j] < h)
						flag = 0;
				}
			}
			if(flag) {
				int sz = (i + 1) * (j + 1);
				if (max_sz < sz)
					max_sz = sz;
			}
		}
	}
	return max_sz;
}
