class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();

        int i=0;
        int j=0;

        for(char c:t){
            if(c==s[j])j++;
            
            if(c==s[i])i++;
            else {
                j = max(j,i+1);
            }

            if(i==n || j==n)return true;
        }
        return false;
    }
};