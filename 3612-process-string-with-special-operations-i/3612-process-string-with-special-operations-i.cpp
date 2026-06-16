class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char &c:s){
            if(c>='a' && c<='z'){
                ans+=c;
            }
            if(c=='*'){
                if(ans.size()>0){
                    ans.pop_back();
                }
            }
            if(c=='#'){
                ans+=ans;
            }
            if(c=='%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};