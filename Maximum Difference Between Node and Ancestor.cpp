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
    void traverse(TreeNode* root,int mx,int mn)
    {
        if(!root)
            return;
        
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        ans=max(ans,abs(mx-mn));
        
        traverse(root->left,mx,mn);
        traverse(root->right,mx,mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        traverse(root,INT_MIN,INT_MAX);
        return ans;
    }
};
