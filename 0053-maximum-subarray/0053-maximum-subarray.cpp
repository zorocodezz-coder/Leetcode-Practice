class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int total_sum=-10000;
        for(int num:nums){
            sum+=num;
            total_sum= max(total_sum,sum);
            sum=sum<0?0:sum;
        }
        return total_sum;
    }
};