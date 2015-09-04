#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk{};
        for(char c : s){
            switch(c){
                case '(':{
                    stk.push(c);
                    break;
                }
                case ')':{
                    if(!stk.empty()){
                        if(stk.top()!='(')
                            return false;
                        else{
                            stk.pop();
                            break;
                        }
                    }
                    else
                        return false;
                }
                case '[':{
                    stk.push(c);
                    break;
                }
                case ']':{
                    if(!stk.empty()){
                        if(stk.top()!='[')
                            return false;
                        else{
                            stk.pop();
                            break;
                        }
                    }
                    else
                        return false;
                }
                case '{':{
                    stk.push(c);
                    break;
                }
                case '}':{
                    if(!stk.empty()){
                        if(stk.top()!='{')
                            return false;
                        else{
                            stk.pop();
                            break;
                        }
                    }
                    else
                        return false;
                }
                default:
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;
    cout<<s.isValid("[");
    return 0;
}