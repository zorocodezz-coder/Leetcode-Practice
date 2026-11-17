class Solution {
public:
    string minWindow(string s, string t) {
        int n=0;
        int i=0;
        int j=0;
        n=t.size();
        int len=INT_MAX;
        int start_i=0;
        int start_j=0;
        if(n>s.size())return "";
        map<char,int> mp;
        for(auto it: t){
            mp[it]++;
        }
        while(j<s.size()){
            if(mp[s[j]]>0){
                n--;
            }
            mp[s[j]]--;
            while(n==0){
                if(len>(j-i+1)){
                    start_i=i;
                    start_j=j;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    n++;
                }
                len=min(len,j-i+1);
                i++;
            }
            j++;
        }
        if(len==INT_MAX)return "";
        return s.substr(start_i,start_j-start_i+1);
    }
};