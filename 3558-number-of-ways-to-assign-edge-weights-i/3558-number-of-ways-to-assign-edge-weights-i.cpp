class Solution {
public:
    int dfs(int i ,unordered_map<int,vector<int>>& adj,vector<int>& visited){
        visited[i]=1;
        int height=0;
        for(auto it:adj[i]){
            if(!visited[it]){
                height = max(height,1+dfs(it,adj,visited));
            }
        }
        return height;
    }
    long long fun(int h){
    long long ans = 1;
    long long mod = 1e9+7;

    for(int i = 0; i < h-1; i++){
        ans = (ans * 2) % mod;
    }

    return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod = 1e9+7;
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int n =adj.size();
        vector<int> visited(n+1,0);
        int  h = dfs(1,adj,visited);
        return (fun(h))%mod;;
    }
};