class Solution {
    public int[] buildArray(int[] nums) {
        int n = nums.length;

        int  ans[] = new int[n];
        for(int i=0;i<nums.length;i++){
            int val = nums[nums[i]];
            ans[i]=val;
        }
        return ans;
    }
}