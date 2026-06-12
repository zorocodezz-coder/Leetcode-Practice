class Solution {
public:
    const int mod = 1e9+7;
    void dfs(vector<int>&parent,vector<int>& lvl,int depth,int node,int par,vector<vector<int>>&adj){
        parent[node] = par;
        lvl[node]=depth;
        for(auto nbr: adj[node]){
            if(nbr!=par)
                dfs(parent,lvl,depth+1,nbr,node,adj);
        }
        return;
    }
    long long fun(int h){
        if(h==0)return 0;
        long long ans=1;
        for(int i=0;i<h-1;i++){
            ans = (ans* 2)%mod;
        }
        return ans;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        vector<long long> power(n+1);
        power[0]=1;
        for(int i=1;i<=n;i++){
            power[i]= (power[i-1]*2)%mod;
        }

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int logN = 17;
        vector<vector<int>> ancestor(n+1,vector<int>(logN,-1));
        vector<int> parent(n+1,0);
        vector<int> lvl(n+1,0);

        dfs(parent,lvl,0,1,-1,adj);
        for(int i=1;i<=n;i++){
            ancestor[i][0]=parent[i];
        }
        for(int j=1;j<logN;j++){
            for(int i=1;i<=n;i++){
                if(ancestor[i][j-1]!=-1){
                    ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
                }
            }
        }
        vector<int> ans;
        for(auto it:queries){
            int n1 = it[0];
            int n2 = it[1];
            if(lvl[n1]<lvl[n2]){
                swap(n1,n2);
            }
            int diff = lvl[n1]-lvl[n2];
            for(int i=0;i<logN;i++){
                if(diff & (1<<i)){
                    n1 = ancestor[n1][i];
                }
            }
        if(n1==n2){
            int l1 = lvl[it[0]];
            int l2 = lvl[it[1]];
            int  h = l1+l2 - (2* lvl[n1]);
            int result = (h == 0) ? 0 : power[h-1];
            ans.push_back(result);
        }else{

            for(int i=logN-1;i>=0;i--){
                    if(ancestor[n1][i]!=ancestor[n2][i]){
                        n1 = ancestor[n1][i];
                        n2 = ancestor[n2][i];
                    }
            }
            int l1 = lvl[it[0]];
            int l2 = lvl[it[1]];
            int  h = l1+l2 - (2* lvl[ancestor[n1][0]]);
            int result = (h == 0) ? 0 : power[h-1];
            ans.push_back(result);
        }
    }
    return ans;
    }
};