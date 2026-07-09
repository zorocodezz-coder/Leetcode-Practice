class Solution {
public:
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unionSet(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

        if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
        }else if(rank[x_par]<rank[y_par]){
            parent[y_par]=x_par;
        }else{
            parent[x_par]=y_par;
            rank[y_par]+=1;
        }
        return;
        
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }

        for(int i=0;i<n-1;i++){
            int u = i;
            int v = i+1;
            int diff = abs(nums[u]-nums[v]);
            if(diff<=maxDiff){
                unionSet(u,v);
            }
        }

        vector<bool> ans;
        for(auto &q:queries){
            int u = q[0];
            int v = q[1];

            int u_par =find(u);
            int v_par = find(v);
            if(u_par == v_par){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};