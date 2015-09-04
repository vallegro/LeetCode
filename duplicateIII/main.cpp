#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ind_val{
public:
    int ind,val;
    ind_val(int i, int v):ind{i},val{v}{};
    bool operator<(ind_val another) const{
        return val<another.val;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<=1) return false;
        vector<ind_val> v{};
        for(int i{0}; i<nums.size(); i++){
            v.push_back(ind_val(i,nums[i]));
        }

        stable_sort(v.begin(),v.end());
        for(int i{0}; i<nums.size()-1; i++){
            int j = i+1;
            while(v[j].val-v[i].val<=t){
                if(abs(v[j].ind-v[i].ind)<=k)
                    return true;
                else
                    j++;
            }
        }
        return false;
    }
};

int main() {
    vector<int> v{1,2};
    Solution s;
    cout<<s.containsNearbyAlmostDuplicate(v,0,1);
    return 0;
}