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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int size=q.size();
            for(int x=0;x<size;x++)
            {
                auto a=q.front();
                q.pop();
                
                TreeNode* node=a.first;
                int vertical=a.second.first;
                int level=a.second.second;
                
                mp[vertical][level].insert(node->val);
                if(node->left)
                {
                    q.push({node->left,{vertical-1,level+1}});
                }
                
                if(node->right)
                {
                    q.push({node->right,{vertical+1,level+1}});
                }
            }    
            
        }
        vector<vector<int>>res;
        for(auto it1: mp)
        {
            vector<int>temp;
            for(auto  it2: it1.second)
            {
                temp.insert(temp.end(),it2.second.begin(),it2.second.end());
            }
            res.push_back(temp);
        }
        return res;
        
    }
};