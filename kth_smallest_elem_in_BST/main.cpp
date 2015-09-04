#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int a = k;
        TreeNode * ans_ptr=kthSmallestRef(root, &a);
        return ans_ptr->val;
    }

    TreeNode * kthSmallestRef(TreeNode* root, int *k){
        TreeNode * ans;
        if(root==nullptr)
            return nullptr;
        if((ans=kthSmallestRef(root->left, k))!=nullptr)
            return ans;
        if(*k==1) return root;
        else {
            *k-=1;
            return kthSmallestRef(root->right, k);
        }

    }
};

int main() {
    TreeNode * root = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution s;
    cout<<s.kthSmallest(root,2);
}