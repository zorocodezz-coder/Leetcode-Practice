class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(costs.begin(),costs.end());
        vector<int> freq(maxi+1,0);
        for(int i=0;i<costs.size();i++){
            freq[costs[i]]++;
        }
        int j=0;
        int i=0;
        while(i<costs.size()){
            while(freq[j]!=0){
                costs[i]=j;
                i++;
                freq[j]--;
            }
            j++;
        }
        int bars=0;
        for(int &c:costs){
            if(c<=coins){
                bars++;
                coins-=c;
            }
        }
        return bars;
    }
};