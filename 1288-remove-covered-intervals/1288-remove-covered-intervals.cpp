class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto lambda = [](auto&a , auto&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }

            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),lambda);
        int n = intervals.size();
        int total=n;
        int end = intervals[0][1];
        for(int i=1;i<n ;i++){
            if(end>=intervals[i][1]){
                total--;
            }else{
                end=intervals[i][1];
            }
        }
        return total;
    }
};