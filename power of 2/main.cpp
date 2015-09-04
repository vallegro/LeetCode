#include <iostream>
//# include <vector>
using namespace std;

bool isPowerOfTwo(int n) {
    int t =1;
    if(n==0) return false;
    cout<<hex<<(n&t);
    while(!(n&t)){
        cout<<"haha";
        n=n>>1;
    }
    if(n==1)
        return true;
    else
        return false;
}
int main() {
    cout << isPowerOfTwo(2) << endl;
    return 0;
}