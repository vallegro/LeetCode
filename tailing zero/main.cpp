#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n<0)
            n = -n;
        if(n==INT_MIN)
            return 0;
        if(n==0)
            return 1;
        int maxzeros = static_cast<int>(floor(log10(static_cast<double>(n))));
        //cout<<maxzeros<<endl;
        int range1{0},range2{maxzeros};

        while(range1<=range2){
            int piv = (range1+range2)/2;
            int base = static_cast<int>(round((pow(10,piv))));
            //cout<<base<<endl;
            if(n%base==0)
                range1 = piv+1;
            else
                range2 = piv-1;
        }
        return range2;
    }
};

int main() {
    Solution s;
    cout<<s.trailingZeroes(1002000000);
    return 0;
}