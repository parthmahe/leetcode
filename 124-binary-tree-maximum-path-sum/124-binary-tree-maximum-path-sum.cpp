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
   int findMax(TreeNode* root, int &maxi)
    {
        if(!root)
            return 0;
        int lsum=max(0,findMax(root->left,maxi));
        int rsum=max(0,findMax(root->right,maxi));
        maxi=max(maxi,root->val+lsum+rsum);
        return root->val+max(lsum,rsum);
    }
    
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findMax(root,maxi);
        return maxi;
    }
};