#include <iostream>
#include <vector>
using namespace std;
class Solution {

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int a = matrix.size();
        if(a==0) return 0;
        int b = matrix[0].size();
        if(b==0) return 0;
        vector<vector<int>> crange_1(a,vector<int>(b,0));
        vector<vector<int>> crange_2(a,vector<int>(b,0));
        for(int i=0; i<a; i++){
            int j=0;
            while(j<b){
                if(matrix[i][j]=='1'){
                    crange_2[i][j] = ccrange_2(matrix, i, j, b);
                    int k=1;
                    while(k<crange_2[i][j]){
                        crange_2[i][j+k]=crange_2[i][j]-k;
                        k++;
                    }
                    j+=k;
                }
                else j+=1;
            }
        }

        for(int j=0; j<b; j++){
            int i=0;
            while(i<a){
                if(matrix[i][j]=='1'){
                    crange_1[i][j] = ccrange_1(matrix, i, j, a);
                    int k=1;
                    while(k<crange_1[i][j]){
                        crange_1[i+k][j]=crange_1[i][j]-k;
                        k++;
                    }
                    i+=k;
                }
                else i+=1;
            }
        }

        int maxa = 0;

        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                int maxv=0;
                for(int k=0; k<crange_1[i][j] ;k++){
                    bool valid = true;
                    for(int l=0; l<=k; l++){
                        if(crange_2[i+l][j]<k+1) {valid=false; break;}
                    }


                    if(valid)
                       maxv =k+1;
                    else
                        break;
                }
                if(maxv>maxa) maxa=maxv;
            }
        }
        return maxa*maxa;
    }


    int ccrange_1(vector<vector<char>>& matrix, int i, int j, int a){
        int ia=i+1;
        while(ia<a){
            if(matrix[ia][j]=='1')
                ia++;
            else{
                break;
            }
        }
        return ia-i;
    }

    int ccrange_2(vector<vector<char>>& matrix, int i, int j, int b){
        int jb=j;
        while(jb<b){
            if(matrix[i][jb]=='1')
                jb++;
            else{
                break;
            }
        }
        return jb-j;
    }

};

int main() {
    vector<vector<char>> matrix(7,vector<char>(4,'1'));
    matrix[0][0]=matrix[0][1]=matrix[0][3]=matrix[3][3]=matrix[4][2]=matrix[4][3]=matrix[6][3]='0';
    //matrix[0][2]=matrix[1][2]='0';
    Solution s;
    cout<<s.maximalSquare(matrix);
    return 0;
}