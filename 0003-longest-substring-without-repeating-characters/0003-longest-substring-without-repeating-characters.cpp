class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int len =0;
        for(;r<s.size();r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            len = max(len,r-l+1);
        }
        return len;
    }
};