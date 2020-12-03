#include<iostream>
#include<algorithm>

#include"alg3.h"

using namespace algorithms::alg3;
using std::min;
using std::pair;

void
algorithms::alg3::task4(vector<vector<int>> &mat, int *ret)
{

}

/*
 * rowisemax calculates the area of maximum size rectangle which
 * is formed given the `height' array. `height' array is a 1D array
 * of integers where each element represents the height of a rectangle
 * with width 1. The maximum area rectangle may encompass multiple such
 * width=1 rectangles partially or fully.
 *
 * It inputs the 1D matrix in form of the a reference to vector of int,
 * a row parameter, pointer to an integer max_sz and pointer to an int
 * array of size 4 to save the co-ordinates of the calculated max sized rectangle.
 */
void
rowisemax(vector<int> &height, int row, int *max_sz, int *ret)
{
        vector<int> s;
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);

        for(uint32_t i=0; i<height.size(); i++) {
                while(!s.empty() && height[i] <= height[s[s.size() - 1]])
                        s.pop_back();
                if(s.empty())
                        left[i] = -1;
                else
                        left[i] = s[s.size() - 1];
                s.push_back(i);
        }

        s.clear();

        for(int i=height.size()-1; i>=0; i--) {
                while(!s.empty() && height[i] <= height[s[s.size() - 1]])
                        s.pop_back();
                if(s.empty())
                        right[i] = height.size();
                else
                        right[i] = s[s.size() - 1];
                s.push_back(i);
        }


        int area, width;
        for(uint32_t i=0; i<height.size(); i++) {
                width = right[i] - left[i] - 1;
                area = height[i] * width;
                if(area > *max_sz) {
                        *max_sz = area;
                        ret[0] = row - height[i] + 1;
                        ret[1] = left[i] + 1;
                        ret[2] = row;
                        ret[3] = right[i] - 1;
                }
        }
}

/*
 * `task5' is the function that carries out the 5th task (bonus) in the assignment.
 * It calculates the largest rectangle in terms of its area given a binary 2D matrix.
 * It iterates over each element in the given 2D array and for each row it aggregates
 * the number of 1s in a 1D array cumulatively with rows prior to it. If instead of 1
 * it encounters zero, the cumulative sum is set to zero for corresponding element in
 * 1D array. For each row it calls the `rowisemax' subroutine by passing current max_sz
 * as well as current 1D cumulative sum.
 *
 * It inputs the binary 2D matrix in form of a reference to a vector of vectors of int
 * along with a pointer to an int array of size 4 (pre-allocated) for it to store the
 * co-ordinates top left and bottom right corners of maximum sized rectangle of 1s.
 */
void
algorithms::alg3::task5(vector<vector<int>> &mat, int *ret)
{
        int max_sz = 0;
        vector<int> height(mat[0].size(), 0);
        for(uint32_t i=0; i<mat.size(); i++) {
                for(uint32_t j=0; j<mat[i].size(); j++) {
                        if(mat[i][j])
                                height[j]++;
                        else
                                height[j]=0;
                }
                rowisemax(height, i, &max_sz, ret);
        }
}
