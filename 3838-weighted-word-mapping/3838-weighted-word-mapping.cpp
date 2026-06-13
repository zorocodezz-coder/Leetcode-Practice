class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &str:words){
            int digit_sum=0;
            for(int i=0;i<str.size();i++){
                digit_sum+=weights[str[i]-'a'];
            }
            int x = digit_sum%26;
            int y = 25-x;
            ans+= (y+'a');
        }
        return ans;
    }
};