class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int l=0;
        int r=0;
        int count=0;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()==3){
                count+=n-r;
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return count;
    }
};