class Solution {
public:
    int minimumCost(vector<int>& cost) {
       sort(cost.begin(),cost.end(),greater());
       int n = cost.size();
       int purchase=0;
       int count =2;
       for(int i=0;i<n;i++){
            if(count==0){
                count=2;
                continue;
            }
            purchase+=cost[i];
            count--;
       }
       return purchase;
    }
};