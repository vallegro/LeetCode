#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double (*op)(double),a{5};
    op =&sqrt;
    cout<<(*op)(a);
}