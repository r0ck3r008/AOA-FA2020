#include<iostream>

#include"algorithms/alg2.h"

using namespace algorithms::alg2;

/*
 * `task3' is the implementation of the brute force algorithm to calculate the max sized
 * rectangle of 1s in a given 2D binary matrix. The subroutine calculates the largest rectange
 * for each window of (i1, j1) and (i2, j2) element within the matrix where 0 <= i1, i2 < rows,
 * 0 <= j1, j2 < cols, i2 <= i1 and j2 <= j1. For each such rectangle, it calculates the area
 * and eventually selects the one with the largest.
 *
 * The subroutine inputs the 2D matrix in the form of a reference to a vector of vectors along
 * with a pointer to an int array of size 4 which must be prealloacted to store the co-ordinates.
 * The function itself does not return anything.
 */
void
algorithms::alg2::task3(vector<vector<int>> &mat, int *ret)
{
	uint32_t max_sz = 0;
        bool flag;
	for(uint32_t i = 0; i < mat.size(); i++) {
		for(uint32_t j = 0; j < mat[i].size(); j++) {
                        uint32_t k, l;
			for(k=i; k < mat.size(); k++) {
				for(l=j; l < mat[i].size(); l++) {
                                        flag = true;
                                        uint32_t x, y;
                                        for(x=i; x<=k && flag; x++) {
                                                for(y=j; y<=l && flag; y++) {
                                                        if(mat[x][y] == 0)
                                                                flag = false;
                                                }
                                        }
                                if(flag) {
                                        uint32_t a = k-i+1, b = l-j+1;
                                        uint32_t sz = a*b;
                                        if (max_sz < sz) {
                                                max_sz = sz;
                                                ret[0] = i;
                                                ret[1] = j;
                                                ret[2] = k;
                                                ret[3] = l;
                                        }
                                }
				}
			}
		}
	}
}
