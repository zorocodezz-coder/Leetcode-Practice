class Solution {
public:
    // tc =  3^n
    // sc = o(n)

    // after dp
    // tc = n^3 // 201*201*201
    // sc = n^3 

    int dp[201][201][201];
    int mod = 1e9+7;
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    int fun(vector<int>&nums,int i,int s1,int s2){
        if(i==nums.size()){
            if(s1==s2)return 1;
            return 0;
        }
        if(dp[i][s1][s2]!=-1){
            return dp[i][s1][s2];
        }
        int skip = fun(nums,i+1,s1,s2);
        int s1_gcd = fun(nums,i+1,gcd(s1,nums[i]),s2);
        int s2_gcd = fun(nums,i+1,s1,gcd(s2,nums[i]));

        return dp[i][s1][s2]= (1LL*skip+s1_gcd+s2_gcd)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(nums,0,0,0)-1;
    }
};