class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> eng;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            eng.push_back({efficiency[i],speed[i]});
        }
        priority_queue<int, vector<int>,greater<int>> pq;
        sort(eng.rbegin(),eng.rend());
        long long sum = 0;
        long long total = 0;
        for(auto &[eq,sp] : eng){
            pq.push(sp);
            sum += sp;
            while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            total = max(total,(long long)sum*eq);
        }
        return (total)%mod;
    }
};