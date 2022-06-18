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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root)
            return res;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            for(int x=0;x<size;x++)
            {
                auto temp=q.front();
                TreeNode* curr=temp.first;
                int level=temp.second;
                q.pop();
                mp[level]=curr->val;
                if(curr->left)
                    q.push({curr->left,level+1});
                if(curr->right)
                    q.push({curr->right,level+1});
                
            }
        }
        for(auto it:mp)
        res.push_back(it.second);
        
        return res;
        
    }
};