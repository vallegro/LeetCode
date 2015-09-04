#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string temp{},ans{};
        while(n>0){
            char t = (n-1)%26+'A';
            temp.push_back(t);
            n = n/26;
        }
        int i{temp.size()-1};
        while(i>=0){
            ans.push_back(temp[i]);
            i--;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout<<s.convertToTitle(27);
    return 0;
}