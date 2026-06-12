/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int fun(Node* root){
      if(root->left ==nullptr && root->right==nullptr)return 1;
      int lf = 0;
      int rf = 0;
      if(root->left){
          lf = fun(root->left);
      }
      if(root->right){
          rf = fun(root->right);
      }
      return 1+lf+rf;
  }
  
  void dfs(Node* root, int par, vector<int>& parent){
      parent[root->data]=par;
      if(root->left){
          dfs(root->left,root->data,parent);
      }
      if(root->right){
          dfs(root->right,root->data,parent);
      }
      return ;
  }
    int kthAncestor(Node *root, int k, int node) {
        // code here
        int maxn=17; // 10^5 = 17 binary string length
        int  n = fun(root); // number of nodes in a tree
        vector<vector<int>> ancestor(n+1,vector<int>(maxn,-1));
        vector<int> parent(n+1,-1);
        
        dfs(root,-1,parent);
        
        for(int i =1;i<=n;i++){
            ancestor[i][0]=parent[i];
        }
        for(int j=1;j<maxn;j++){
            for(int i =1;i<=n;i++){
                if(ancestor[i][j-1]==-1){
                    ancestor[i][j]=-1;
                }else{
                    ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
                }
            }
        }
        int node_temp = node;
        for(int i=0;i<maxn;i++){ // 100 - 1100100
            if(k&(1<<i)){
                if(ancestor[node][i]==-1){
                    return -1;
                }node_temp = ancestor[node_temp][i];
            }
        }
        return node_temp;
    }
};
