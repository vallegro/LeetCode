#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool overflow{false};
        if(divisor==0) return INT_MAX;
        if(divisor==INT_MIN) {
            if(dividend==INT_MIN) return 1;
            else return 0;
        }
        if(dividend==INT_MIN){
            dividend +=1;
            overflow = true;
        }

        int ans=0;
        bool n1{false},n2{false};
        if(dividend<0) {
            n1=true;
            dividend=-dividend;
        }
        if(divisor<0) {
            n2=true;
            divisor=-divisor;
        }
        while(dividend>=divisor){
            int di = divisor;
            int step = 1;
            while(dividend>=di){
                dividend-=di;
                ans+=step;
                step +=step;
                int di1=di+di;
                if(di1>0)
                    di=di1;
            }
        }
        if (overflow){
            dividend+=1;
            if(dividend==divisor)
                ans+=1;
        }

        if(n1^n2) return -ans;
        else {
            if(ans<0) return INT_MAX;
            else    return ans;}
    }
};

int main() {
    Solution s;
    cout<<s.divide(-2147483648, -1);
    return 0;
}