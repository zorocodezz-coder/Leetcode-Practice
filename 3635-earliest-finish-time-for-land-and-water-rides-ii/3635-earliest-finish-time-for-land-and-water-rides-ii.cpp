class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n  = landStartTime.size();
        int m = waterStartTime.size();
        int landMini =INT_MAX;
        int waterMini = INT_MAX;
        for(int i=0;i<n;i++){
            landMini = min(landMini,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            waterMini = min(waterMini,waterStartTime[i]+waterDuration[i]);
        }
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        for(int i=0;i<m;i++){
            if(landMini>=waterStartTime[i]){
                mini1 = min(mini1,landMini+waterDuration[i]);
            }else{
                mini1= min(mini1,waterStartTime[i]+waterDuration[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(waterMini>=landStartTime[i]){
                mini2 = min(mini2,waterMini+landDuration[i]);
            }else{
                mini1= min(mini1,landStartTime[i]+landDuration[i]);
            }
        }
        return min(mini1,mini2);
    }
};