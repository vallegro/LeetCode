#include <iostream>

using namespace std;

int main() {
    int n = 0; for(double i = 0; i < 1; i+=0.1) {cout<<n; n++;} cout<<n<<endl;

    n = 0; for(float i = 0; i < 1; i+=0.1) n++; cout<<n<<endl;
    return 0;
}