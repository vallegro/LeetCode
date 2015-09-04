#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = parser(version1);
        auto v2 = parser(version2);
        if(v1.size()<v2.size())
            pad(&v1,v2.size());
        else if(v1.size()>v2.size())
            pad(&v2,v1.size());
        return compare(v1,v2);
    }

    vector<int> parser(string version){
        stringstream st(version);
        vector<int> ans{};
        int a{0};
        st>>a;
        ans.push_back(a);
        st.get();
        while(st){
            st>>a;
            ans.push_back(a);
            st.get();
        }
        //cout<<a<<" "<<b<<endl;
        return ans;
    };

    void pad(vector<int> *v, int l){
        while(v->size()<l){
            v->push_back(0);
        }
    }

    int compare(vector<int> a,vector<int> b){
        for(int i{0};i<a.size();i++){
            if(a[i]>b[i])
                return 1;
            if(a[i]<b[i])
                return -1;
        }
        return 0;
    }
};


int main() {
    Solution s;
    cout<<s.compareVersion("1.0.0","1");
    return 0;
}