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
    void recursion(TreeNode* root,int level,map<int,int>&mp)
    {
        if(!root)
            return;
        
        if(!mp.count(level))
            mp[level]=root->val;
        
        recursion(root->right,level+1,mp);
        recursion(root->left,level+1,mp);
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root)
            return res;
        map<int,int>mp;
        
        recursion(root,0,mp);
        
        for(auto it:mp)
        res.push_back(it.second);
        
        return res;
        
    }
};