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
    string solve(TreeNode*root,map<string,int>&m,vector<TreeNode*>&ans)
    {
        if(!root) return "*";
        string left=solve(root->left,m,ans);
        string right=solve(root->right,m,ans);
        string s=to_string(root->val)+"*"+left+"*"+right; 
        // [2,1,11,11,null,1] output will come [[11,1]] * needed to avoid this 
        // but correct output is []
        if(m[s]==1)
        {
            ans.push_back(root);
        }
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        map<string,int>m;
        solve(root,m,ans);
        return ans;
    }
};