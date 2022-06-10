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
    void backtrack(TreeNode* root,int target,int op,bool &res)
    {
        if(root==NULL)
        {
            if(target==op)
                res=true;
            return;
        }
        
        int op1=op;
        int op2=op;
        if(!root->left && !root->right)
        {
            backtrack(root->left,target,op1,res);
        }
        if(root->left)
        {
            op1+=root->left->val;
            backtrack(root->left,target,op1,res);
        }
        if(root->right)
        {
            op2+=root->right->val;
            backtrack(root->right,target,op2,res);
        }
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res=false;
        if(!root)
            return false;
        backtrack(root,targetSum,root->val,res);
        return res;
    }
    
};