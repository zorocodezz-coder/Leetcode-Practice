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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> mp;
        TreeNode* root;
        for(int i=0;i<descriptions.size();i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int is_left = descriptions[i][2];
            if(mp.find(parent)!=mp.end()){
                root = mp[parent];
                if(mp.find(child)!=mp.end()){
                    TreeNode* children = mp[child];
                    if(is_left){
                        root->left = children;
                    }else{
                        root->right=children;
                    }
                }else{
                    TreeNode* children = new TreeNode(child);
                    mp[child]=children;
                    if(is_left){
                        root->left = children;
                    }else{
                        root->right = children;
                    }
                }
            }else{
                root = new TreeNode(parent);
                mp[parent]=root;
                if(mp.find(child)!=mp.end()){
                    TreeNode* children = mp[child];
                    if(is_left){
                        root->left = children;
                    }else{
                        root->right=children;
                    }
                }else{
                    TreeNode* children = new TreeNode(child);
                    mp[child]=children;
                    if(is_left){
                        root->left = children;
                    }else{
                        root->right = children;
                    }
                }
            }
        }
        for(auto &it:descriptions){
            mp.erase(it[1]);
        }
        return mp.begin()->second;
    }
};