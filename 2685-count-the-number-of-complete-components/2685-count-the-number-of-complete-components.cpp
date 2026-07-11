class Solution {
public:
// tc  = o(v+e)

// sc  = o(v)
void dfs(int u,unordered_map<int,vector<int>>&adj,vector<int>&visited,int &nodes,int &edges){ // O(v+e)
        visited[u]=1;
        nodes++;

        edges+= adj[u].size();
        for(auto &v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited,nodes,edges);
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){ // o(e)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int comp=0;
        vector<int> visited(n,0); // o(v)
         for(int i=0;i<n;i++){  // (n)
            if(!visited[i]){
                int nodes=0;
                int edges=0;
                dfs(i,adj,visited,nodes,edges);
                edges/=2;
                if(edges == ((nodes-1)*nodes)/2){
                    comp++;
                }
            }
        }
        return comp;
    }
};