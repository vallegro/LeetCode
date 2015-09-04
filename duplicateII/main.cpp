#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ind_val {
public:
    ind_val(int i, int v):ind{i},val{v}{};
    inline int get_val(){
        return val;
    }
    inline int get_ind(){
        return ind;
    }
    bool operator<(ind_val another) const{
        return val<another.val;
    }
    int ind,val;
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<ind_val> vec{};
        for(int i{0}; i<nums.size() ;i++){
            vec.push_back(ind_val(i,nums[i]));
        }
        stable_sort(vec.begin(),vec.end());
        for(int i{0}; i<nums.size()-1 ; i++){
            if(vec[i].val!=vec[i+1].val)
                continue;
            else if (vec[i+1].ind - vec[i].ind <=k){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3,4,2,3,4,32432};
    cout<<s.containsNearbyDuplicate(nums,3);
}