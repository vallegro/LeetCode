#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class ind_val{
public:
    int ind, val;
    ind_val(int i, int v):ind{i},val{v}{};
    bool operator<(ind_val a) const {return val<a.val;};
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<ind_val> v{};
        for(int i{0}; i<nums.size(); i++){
            v.push_back(ind_val(i,nums[i]));
        }
        sort(v.begin(),v.end());
        for(int i{0}; i<v.size(); i++){
            int other = target -v[i].val;
            auto j = b_search(v,i+1,v.size(), other);
            if(j>=0){
                if(v[i].ind<v[j].ind)
                    return vector<int>{v[i].ind+1,v[j].ind+1};
                else
                    return vector<int>{v[j].ind+1,v[i].ind+1};
            }
        }
    }

    int b_search(vector<ind_val>& v,int range1, int range2, int target ){
        int pivot = (range1+range2)/2;
        while(range1<=range2){
            if(v[pivot].val == target){
                return pivot;
            }
            else if(v[pivot].val < target){
                range1 = pivot+1;
            }
            else{
                range2 = pivot-1;
            }
            pivot = (range1+range2)/2;
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> in{3,2,4};
    auto a= s.twoSum(in,6);
    cout<<a[0]<<a[1]<<endl;
}