class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> temp;

        for(int i=0;i<n;i++){
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans(n,1);
        int rank = 1;
        for(int i=1;i<n;i++){
            if(temp[i].first>temp[i-1].first){
                rank++;
                ans[temp[i].second] = rank;
            }else{
                ans[temp[i].second]=rank;
            }
        }
        return ans;
    }
};