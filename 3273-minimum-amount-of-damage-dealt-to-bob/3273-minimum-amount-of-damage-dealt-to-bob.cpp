class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        
        int n = damage.size();
        long long total_damage=0;
        vector<pair<int,int>> enimes;

        for(int i=0;i<n;i++){
            enimes.push_back({damage[i],health[i]});
            total_damage+= damage[i];
        }
        auto lambda= [&](auto &a, auto &b){
            double dpha = 1.0* a.first/((a.second+power-1)/power);
            double dphb = 1.0* b.first/((b.second+ power-1)/power);

            if(dpha>dphb) return true;
            return false;
        };
        sort(enimes.begin(),enimes.end(),lambda);
        long long ans=0;
        for(int i=0;i<n;i++){
            int t  = (enimes[i].second+power-1)/power;
            ans+=(total_damage*t);
            total_damage-=enimes[i].first;
        }
        return ans;
    }
};