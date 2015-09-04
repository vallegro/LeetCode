#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> g_reserved
        {
                "the",
                "quick",
                "brown",
                "fox",
                "jumps",
                "over",
                "the",
                "lazy",
                "dog"
        };

bool IsReserved(const string &s)
{
    return g_reserved.end() !=
           find(g_reserved.cbegin(), g_reserved.cend(), s);
}

int main()
{
    string a{"fax"};
    a[1]='o';
    cout << boolalpha

    << IsReserved(a)
    << ' '
    << IsReserved("zebra")
    << endl;

    return 0;
}