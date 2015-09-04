#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int invcur2= num2.size()-1, invcur1{0}, invcurt{0}, invcura{0};
        int carry_dig_m, carry_dig_p;
        string ans(num1.size()+num2.size(),'0');
        while(invcur2>=0){
            string temp(num1.size()+1,'0');
            carry_dig_m = 0;
            invcur1 = num1.size()-1;
            while(invcur1>=0){
                invcurt = invcur1+1;
                int dig_temp = (num1[invcur1]-'0')*(num2[invcur2]-'0')+carry_dig_m;
                carry_dig_m = dig_temp/10;
                temp[invcurt] = static_cast<char>('0'+(dig_temp-carry_dig_m*10));
                invcur1--;
            }
            invcurt = 0;
            temp[invcurt] = static_cast<char>('0'+carry_dig_m);
            invcurt = temp.size()-1;
            invcura = ans.size()-(num2.size()-invcur2);
            carry_dig_p=0;
            while(invcurt>=0){
                int dig_temp =(ans[invcura]-'0')+(temp[invcurt]-'0')+carry_dig_p;
                carry_dig_p = dig_temp/10;
                ans[invcura] = static_cast<char>('0'+(dig_temp-carry_dig_p*10));
                invcurt--;
                invcura--;
            }
            invcur2--;
        }
        while(ans[0]=='0'&&ans.size()>1){
            ans.erase(0,1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    string a= s.multiply("109","109");
    cout<<a;
    return 0;
}