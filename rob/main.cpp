#include <iostream>
#include <vector>
using namespace std;

enum status{RD, TR};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<status> street( nums.size(),TR);
        return robone(nums,street,0);

    }

    int robone(vector<int>& nums, vector<status>& street,int level){
        int max{0},temp{0};
        for(int i{0};i<nums.size();i++){
            if(safeU(street,i)) {
                street[i] = RD;
                cout<<"lvl"<<level<<":";
                for(auto i:street)
                    cout<<i;
                cout<<endl;
                temp = nums[i] + robone(nums, street, level+1);
                if (temp > max) {
                    max = temp;
                }
                street[i] = TR;
            }
        }
        return max;
    }

    bool safeU(vector<status>& street,int i){
        if(street[i]==RD) return false;
        if(i==0)
            return street[i+1]!=RD;
        if(i==street.size())
            return street[i-1]!=RD;
        else
            return (street[i-1]!=RD)&&street[i+1]!=RD;
    }
};

int main() {
    Solution s;
    vector<int> houses{1,1,3,6,7,1};
    cout<<s.rob(houses);
    return 0;
}