#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands{};
        int i{0}, opi,opri, oprj;
        while(i<tokens.size()){
            if(tokens[i][tokens[i].size()-1]>='0'&&tokens[i][tokens[i].size()-1]<='9'){
                istringstream(tokens[i])>>opi;
                operands.push(opi);
            }
            else if(tokens[i][0]=='+'){
                opri = operands.top();
                operands.pop();
                oprj = operands.top();
                operands.pop();
                operands.push(oprj+opri);
            }
            else if(tokens[i][0]=='-'){
                opri = operands.top();
                operands.pop();
                oprj = operands.top();
                operands.pop();
                operands.push(oprj-opri);
            }
            else if(tokens[i][0]=='*'){
                opri = operands.top();
                operands.pop();
                oprj = operands.top();
                operands.pop();
                operands.push(oprj*opri);
            }
            else if(tokens[i][0]=='/'){
                opri = operands.top();
                operands.pop();
                oprj = operands.top();
                operands.pop();
                operands.push(oprj/opri);
            }
            i++;
        }
        return operands.top();
    }
};
int main() {
    vector<string> v {"3","-4","+"};
    Solution s;
    cout<<s.evalRPN(v);
    return 0;
}