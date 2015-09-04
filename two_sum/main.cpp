#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stl_queue.h>

using namespace std;
class SolutionBF {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int indexi = 0; indexi < nums.size(); indexi++) {
            int j = target - nums[indexi];
            for (int indexj = indexi + 1; indexj < nums.size(); indexj++) {
                if (nums[indexj] == j) {
                    vector<int> ans{indexi + 1, indexj + 1};
                    return ans;
                }
            }
        }
    }
};

class SolutionSEQVEC {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int indexi = 0; indexi<nums.size(); indexi++) {
            int j = target - nums[indexi];
            int range1 = indexi+1;
            int range2 = nums.size()-1;
            int indexj = (range1+range2)/2;
            while(range2>=range1){
                if(nums[indexj]==j){
                    vector<int> ans{indexi+1,indexj+1};
                    return ans;
                }
                else if(nums[indexj]>j){
                    range2 = indexj-1;
                    indexj = (range1+range2)/2;
                }
                else{
                    range1 = indexj+1;
                    indexj = (range1+range2)/2;
                }
            }
        }
        vector<int> ans{-1,-1};
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int indexi = 0; indexi<nums.size(); indexi++) {
            int j = target - nums[indexi];
            priority_queue pnums(nums.begin()+indexi+1,nums.end(),greater<int>());
            while(true){

            }
        }
    }
};

int main() {
    vector<int> h{1,2,3,4};
    Solution s;
    auto ans = s.twoSum(h,5);
    cout<<ans[0]<<ans[1];
    return 0;
}