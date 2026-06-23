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
    void fun(TreeNode* root, vector<int> & ans){
        if(root==nullptr)return;
        ans.push_back(root->val);
        if(root->left !=nullptr){
            fun(root->left, ans);
        }
        if(root->right !=nullptr){
            fun(root->right, ans);
        }

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        fun(root,ans);
        return ans;
    }
};