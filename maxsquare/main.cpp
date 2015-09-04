#include <iostream>
#include <vector>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int OLX, OLY;
    int sum = (C-A)*(D-B)+(G-E)*(H-F);
    if(A>=G||E>=C||B>=H||F>=D)
        return sum;
    else{
        cout<<(A>E?A:E);
        cout<<(C>G?G:C);
        cout<<(OLX = -(A>E?A:E)+(C>G?G:C));
        cout<<(OLY = -(B>F?B:F)+(D>H?H:D));
        int total = sum-OLX*OLY;
        return total;
    }
}

int main() {
    cout<<computeArea(-2,-2,2,2,-2,-2,2,2);
}