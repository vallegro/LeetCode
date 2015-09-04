#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        long  size1 = dungeon.size(), size2 = dungeon[0].size();
        vector<vector<int>> min_health(size1, vector<int>(size2,-1)); //-1: not calculated; >=0: health needed
        return minHP(dungeon, min_health,0,0)+1;

    }

    int minHP(vector<vector<int>> & dungeon, vector<vector<int>> & min_health, int i1, int i2){
        int minHp;
        if (min_health[i1][i2] >=0)
            return min_health[i1][i2];
        else{
            vector<vector<int>> coor{};
            int ahead{INT_MAX};
            if(i2 ==dungeon[0].size()-1 && i1 == dungeon.size()-1)
                ahead = 0;
            else {
                if (i2 < dungeon[0].size() - 1)
                    coor.push_back(vector<int>{i1, i2 + 1});
                if (i1 < dungeon.size() - 1)
                    coor.push_back(vector<int>{i1 + 1, i2});
                int temp{-2};
                for (int i{0}; i < coor.size(); i++) {
                    if ((temp = minHP(dungeon, min_health, coor[i][0], coor[i][1]) )< ahead)
                        ahead = temp;
                }
            }
            minHp = ahead - dungeon[i1][i2] ;
            if (minHp<0)
                minHp = 0;
            min_health[i1][i2] =minHp;
            return minHp;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> a(2,vector<int>(2,-5));
    a[0][1] =0;
    cout<<s.calculateMinimumHP(a);
}