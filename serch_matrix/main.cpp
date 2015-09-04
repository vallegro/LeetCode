#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rrange1{0},rrange2=matrix.size()-1,rpiv{};
        while (rrange1<=rrange2){
            rpiv = (rrange1+rrange2)/2;
            if(matrix[rpiv][0] == target)
                return true;
            else if(matrix[rpiv][0] > target)
                rrange2 = rpiv-1;
            else
                rrange1 = rpiv+1;
        }
        rpiv = rrange2;
        if(rpiv <0) return false;
        if(matrix[rpiv].size()==0) return false;
        unsigned long crange1{0},crange2=matrix[rpiv].size()-1,cpiv{};
        while(crange1<=crange2){
            cpiv =(crange1+crange2)/2;
            if(matrix[rpiv][cpiv]==target)
                return true;
            else if(matrix[rpiv][cpiv]>target)
                crange2 = cpiv-1;
            else
                crange1 = cpiv+1;
        }
        return false;
    }
};


int main() {
    vector<vector<int>> a{vector<int>{1}};
    Solution s;
    cout<< s.searchMatrix(a,0);
    return 0;
};