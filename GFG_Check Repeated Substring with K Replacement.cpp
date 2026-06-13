class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        unordered_map<string,int> mp;
        
        for(int i=0;i<s.size();i+=k){
            string str = s.substr(i,k);
            mp[str]++;
        }
        
        if(mp.size()>2)return false;
        if(mp.size()==1)return true;
        
        int mini_substring_occurance = INT_MAX;
        for(auto &it:mp){
            mini_substring_occurance= min(mini_substring_occurance,it.second);
        }
        
        return mini_substring_occurance==1;
        
    }
};
