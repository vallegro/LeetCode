#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int dep = depth(root);
        if (dep==0) return 0;
        if (dep==1) return 1;
        int max_last = pow(2,(dep -1))-1;
        int base = max_last;
        int range1 =0, range2=max_last;
        int target  = (range1+range2)/2;
        //out<<range1<<range2<<target<<endl;
        bool has = false;
        while(range1<range2){
            has = hasLeaf(root, target, dep);
            //cout<<range1<<range2<<target<<has<<endl;
            if(has)
                range1 = target+1;
            else
                range2 = target;
            target  = double(range1+range2)/2;
        }
        target  = (range1+range2)/2;
        has = hasLeaf(root, target, dep);
        //cout<<range1<<range2<<target<<has<<endl;
        return base+target+has;

    }

    int depth(TreeNode* root){
        int depth = 0;
        while(root!=nullptr){
            depth ++;
            root = root->left;
        }
        return depth;
    };

    bool hasLeaf(TreeNode* root,int target, int depth){
        //cout<<target<<"in hasLeaf"<<endl;
        if (depth <=2)
            if(target==0)
                return root->left!= nullptr;
            else
                return root->right!= nullptr;
        int half = pow(2,depth-2);
        if(target>=half){
            root=root->right;
            target = target -half;
        }
        else
            root=root->left;
        return hasLeaf(root, target, depth-1);
    };

    TreeNode* cbt_con(int num){//complete binary tree construction
        for(int i=1; i<=num; i++ ){
            TreeNode
        }
    }
};

int main() {
    TreeNode a1(0),a2(0),a3(0),a4(0),a5(0);
    Solution s;
    a1.left= &a2;
    a1.right= &a3;
    a2.left = &a4;
    a2.right= &a5;
    cout <<s.countNodes(&a1)<<endl;
    //cout <<s.hasLeaf(&a1,1,2)<<endl;
    return 0;
}