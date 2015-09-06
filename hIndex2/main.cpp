#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i{0}, hindex{citations.size()};
        if(!hindex) return 0;
        while(citations[i]<hindex){
            hindex--;
            i++;
        }
        return hindex;
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,3,4,5,6};
    cout<<s.hIndex(v);
    return 0;
}