class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        // we have to find the greates number in candies /// 5 

        // candies[i] + extra canide >= max_candi
        int n = candies.length;
        int maxCandies=0;
        for(int i=0;i<n;i++){
            if(maxCandies<candies[i]){
                maxCandies=candies[i];
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxCandies){
                ans.add(true);
            }else{
                ans.add(false);
            }
        }

        return ans;
    }
}