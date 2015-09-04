#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pc{-1};
        bool common{true};
        if(strs.size()==0){
            return string{};
        }
        else if(strs.size()==1){
            return strs[0];
        }
        while(common){
            pc++;
            for(int ps=1;ps<strs.size();ps++){
                if(pc<=strs[0].size()&&pc<=strs[ps].size()){
                    if(strs[0][pc]!=strs[ps][pc]){
                        common=false;
                        break;
                    }
                }
                else{
                    common= false;
                    break;
                }
            }
        }
        return strs[0].substr(0,pc);
    }
};

int main() {
    Solution s;
    vector<string> a{"a","b"};
    cout<<s.longestCommonPrefix(a);
    return 0;
}