/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = -1;
    stack<int> st;
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return ans;
    }
    void f(TreeNode* root, int &k){
        if( root == nullptr or ans!= -1) return;
        f(root->left,k);

        k-=1;
        if( k == 0){
            ans =  root->val;
            return;

        } 
        else{
            f(root->right,k);
        }
    return;
    }
};
