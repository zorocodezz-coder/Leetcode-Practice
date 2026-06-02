class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int t = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0;i<n;i++){
            int land = landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                if(land>=waterStartTime[j]){
                    t = min(t,land+waterDuration[j]);
                }else{
                    t = min(t,waterStartTime[j]+waterDuration[j]);
                }
            }
        }
        for(int i=0;i<m;i++){
            int water = waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                if(water>=landStartTime[j]){
                    t = min(t,water+landDuration[j]);
                }else{
                    t = min(t,landStartTime[j]+landDuration[j]);
                }
            }
        }
        return t;
    }
};