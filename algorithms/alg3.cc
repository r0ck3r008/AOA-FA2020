#include<iostream>

#include"algorithms/alg3.h"

using namespace algorithms::alg3;
using std::max;

int
algorithms::alg3::task4(vector<vector<int>> &mat, int *ret)
{
        int max_sz = 0;

        return max_sz;
}

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
