class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int max_peak=0;
        for(int &g:gain){
            sum+=g;
            max_peak=max(max_peak,sum);
        }
        return max_peak;
    }
};