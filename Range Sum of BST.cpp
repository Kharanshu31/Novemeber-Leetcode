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
    int ans=0;
    int x=0,y=0;
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
        
        if(x<=root->val && root->val<=y)
            ans+=root->val;
        
        preorder(root->left);
        preorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        x=low;
        y=high;
        preorder(root);
        return ans;
    }
};
