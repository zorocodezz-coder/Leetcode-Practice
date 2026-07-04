class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> visited(n+1,0);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
            
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({INT_MAX,1});
        int ans = INT_MAX;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int city = it.first;
            int node = it.second;
            if(visited[node]==1)continue;
            visited[node]=1;
            ans = min(ans,city);

            for(auto it:adj[node]){
                int C = it.second;
                int N  = it.first;
                if(visited[N]==1)continue;
                pq.push({C,N});
            }
        }
        return ans;
    }
};