class Solution {
public:
    int fun(vector<int>& nums){
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
        return sum;
    }

    bool fun1(int sum, vector<int> & nums, int i,int total,vector<vector<int>> & dp ){
        if(total==sum)return true;
        if(i==nums.size())return false;
        if(total>sum)return false;
        bool take=false;
        bool not_take = false;
        if(dp[i][total]!=-1){
            if(dp[i][total]==0) return false;
            else return true;
        }
       take =  fun1(sum,nums,i+1,total+nums[i],dp);
       not_take = fun1(sum,nums,i+1,total,dp);
       return dp[i][total]= take||not_take;
    }
    bool canPartition(vector<int>& nums) {
       int sum = fun(nums);
       vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));

        if(sum%2==1)return false;

        if(fun1(sum/2,nums,0,0,dp)){
            return true;
        }
        return false;
    }
};