class Solution {
public:
    long long  fun(int mid,vector<int>& piles){
        long long  total=0;
        for(auto it: piles){
            total+= (it+(mid-1))/mid;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());

        int lower=1;
        int higher=piles[piles.size()-1];

        while(lower<=higher){
            int mid = lower+(higher-lower)/2;

            long long K = fun(mid,piles);
            if(K>h){
                lower=mid+1;
            }else{
                higher=mid-1;
            }
        }
        return lower;
    }
};