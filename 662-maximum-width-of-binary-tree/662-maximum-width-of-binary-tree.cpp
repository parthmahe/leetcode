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
    int widthOfBinaryTree(TreeNode* root) {
         queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int max_width=0;
        while(!q.empty())
        {
            int size=q.size();
            long long min=q.front().second;
            for(int x=0;x<size;x++)
            {
                auto temp=q.front();
                q.pop();
                max_width=max_width>temp.second-min+1?max_width:temp.second-min+1;
                if(temp.first->left)
                q.push({temp.first->left,2*(temp.second-min)+1});
                if(temp.first->right)
                q.push({temp.first->right,2*(temp.second-min)+2});
            }
        }
        return max_width;
        
    }
};