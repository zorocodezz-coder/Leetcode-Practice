class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s ="123456789";
        
        for(int len = 2;len<=9;len++){
            for(int j=0;j<=9-len;j++){
                int num = stoi(s.substr(j,len));

                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};