#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class child{
public:
    child(int r, int i):rating{r},ind{i}{};
    bool operator<(child b)const{
        return rating<b.rating;
    }
    int rating,ind;
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int i{0};
        vector<child> c{};
        vector<int> candy(ratings.size(),0);
        while(i<ratings.size()){
            c.push_back(child{ratings[i],i});
            i++;
        }
        sort(c.begin(),c.end());
        i=0;
        while(i<c.size()){
            if(c[i].ind==0){
                if(ratings[c[i].ind]>ratings[c[i].ind+1]){
                    candy[c[i].ind] = candy[c[i].ind+1]+1;
                }
                else{
                    candy[c[i].ind] = 1;
                }
            }
            else if(c[i].ind==ratings.size()-1){
                if(ratings[c[i].ind]>ratings[c[i].ind-1]){
                    candy[c[i].ind] = candy[c[i].ind-1]+1;
                }
                else{
                    candy[c[i].ind] = 1;
                }
            }
            else{
                int l,r;
                if(ratings[c[i].ind]>ratings[c[i].ind-1]){
                    l = candy[c[i].ind-1]+1;
                }
                else{
                    l = 1;
                }
                if(ratings[c[i].ind]>ratings[c[i].ind+1]){
                    r = candy[c[i].ind+1]+1;
                }
                else{
                    r = 1;
                }
                candy[c[i].ind] = max(r,l);
            }
            i++;
        }
        int can{0};
        for(auto can_cld : candy){
            can+=can_cld;
        }
        return can;
    }
};

int main() {
    vector<int>ratings{1,2,3,3,3,2,1 };
    Solution s;
    cout<<s.candy(ratings);
    return 0;
}