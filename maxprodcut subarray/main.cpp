#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i{0},j{0},cur{0}, ans{INT_MIN};
        bool nzsubv{false}, hasnzs{false}, hasz{false};
        while(true){
            if(!nzsubv){
                if(cur>=nums.size())
                    break;
                if(!nums[cur]) {
                    cur++;
                    hasz = true;
                }
                else{
                    i = cur;
                    nzsubv = true;
                    cur++;
                }
            }
            else {
                if(cur>=nums.size()) {
                    j = cur-1;
                    hasnzs = true;
                    int temp = maxP(nums,i,j);
                    ans = ans>temp?ans:temp;
                    break;
                }
                if (nums[cur]) {
                    cur++;
                }
                else{
                    j = cur-1;
                    hasnzs = true;
                    hasz = true;
                    int temp = maxP(nums,i,j);
                    ans = ans>temp?ans:temp;
                    nzsubv = false;
                    cur++;
                }
            }
        }
        if(hasnzs)
            if(hasz&&ans<0)
                return 0;
            else
                return ans;
        else
            return 0;
    }

    int maxP(vector<int>& nums, int i, int j){
        if(i==j)
            return nums[i];
        int cur{i},negc{0},ans{1};
        while(cur<=j){
            if(nums[cur]<0)
                negc++;
            ans *= nums[cur];
            cur++;
        }

        if(negc%2){
            int pro{1},epi{1};
            cur = i;
            while(nums[cur]>0){
                pro *= nums[cur];
                cur++;
            }
            pro *= nums[cur];

            cur = j;
            while(nums[cur]>0){
                epi *= nums[cur];
                cur--;
            }
            epi *= nums[cur];

            if(pro>epi)
                ans /=pro;
            else
                ans /=epi;
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> a{-1,0,-2};
    cout<<s.maxProduct(a);
    return 0;
}