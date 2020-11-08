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
    
    int tsum=0;
    int find(TreeNode* root){
        if(root==NULL)
            return 0;
        int lsum= find(root->left);
        int rsum=find(root->right);
        tsum=tsum+abs(lsum-rsum);
        return lsum+rsum+root->val;
    }
    
    int findTilt(TreeNode* root) {
        find(root);
        return tsum;
    }
};
