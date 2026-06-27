class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long , int > mp;
        long long ones=0;
        for(int n:nums){
            mp[n]++;
            if(n==1)ones++;
        }
        long long ans=0;
        for(int n:nums){
            if(n==1)continue;
            long long t=0;
            long long x=n;
            while(mp.find(x)!=mp.end()){
                if(mp[x]>=2)t+=2;
                else if(mp[x]==1){
                    t++;
                    break;
                }
                x*=x;
                if(mp.find(x)==mp.end()){
                    t--;
                    break;
                }

            }
            ans= max(ans,t);
        }
        if(ones%2==0){
            ones--;
        }
        ans=max(ans,ones);
        return ans;
    }
};