#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphica(string s, string t) {
        vector<char> cv(256,0);
        char c;
        if(s.size()!=t.size())
            return false;
        int i = 0;
        while(i < s.size()){
            int ind = s[i];
            if(c = cv[ind]){
                if(t[i] !=c)
                    return false;
            }
            else{
                cv[ind] = t[i];
            }
            i++;
        }
        return true;
    }

    bool isIsomorphic(string a, string b){
        return isIsomorphica(a,b)&&isIsomorphica(b,a);
    }
};

int main() {
    Solution s;
    cout<<s.isIsomorphic("ab", "aa");
    return 0;
}