#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i{0},hindex{0};
        while(i<citations.size()&&hindex<citations[i]){
            hindex++;
            i++;
        }
        return hindex;
    }
};

int main() {
    Solution s;
    vector<int> c {6,6,6};
    cout<<s.hIndex(c)<<endl;
}