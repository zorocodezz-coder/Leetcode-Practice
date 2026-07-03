class Solution {
public:

    int lastNode;
   bool isReach(int mid,
             unordered_map<int,vector<pair<int,int>>> &adj,
             vector<bool>& online,
             long long k)
{
    int n = online.size();
    vector<long long> dis(n, LLONG_MAX);

    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> pq;

    

    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        if (currDist > dis[node]) continue;

        for (auto &nbr : adj[node]) {
            int nbr_node = nbr.first;
            int wt = nbr.second;

            if (!online[nbr_node]) continue;
            if (wt < mid) continue;

            if (currDist + wt < dis[nbr_node] &&
                currDist + wt <= k) {

                dis[nbr_node] = currDist + wt;
                pq.push({dis[nbr_node], nbr_node});
            }
        }
    }

    return dis[lastNode] <= k;
}

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        int r=0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            r = max(r,it[2]);
        }
        lastNode=online.size()-1;
        int l=0;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;

            if(isReach(mid,adj,online,k)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};