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
    map<TreeNode*,int>m;
    int rob(TreeNode* root) {
        if(!root)
           return 0;
        if(m.find(root)!=m.end())
            return m[root];
        
        int sum=0;
        if(root->left)
        {
            sum+=rob(root->left->left);
            sum+=rob(root->left->right);
        }
        
        if(root->right)
        {
            sum+=rob(root->right->left);
            sum+=rob(root->right->right);
        }
        
        int newsum=rob(root->left)+rob(root->right);
        int res=max(root->val+sum,newsum);
        m[root]=res;
        return res;
        
    }
};
