class Solution {
public:
    char processStr(string s, long long k) {
        long long len =0;
        vector<long long> lengths;
        for(char &c:s){
            if(c>='a' && c<='z'){
                len++;
            }else if(c=='*'){
               len=max(0LL, len-1);
            }else if(c=='%'){
                
            }else if(c=='#'){
                len = 2*len;
            }
            lengths.push_back(len);
        }
        if(len<=k)return '.';
        
        //back
        for(int i=s.size()-1;i>=0;i--){
            len = lengths[i];
            if(s[i]>='a' && s[i]<='z'){
                if(len == k+1)  return s[i];
            }
            else if(s[i]=='*'){
             //ignore
            }else if(s[i]=='#'){
                long long prev_len = len/2;
                if(k>=prev_len){
                    k=k-prev_len;
                }
            }else if(s[i]='%'){
                k=len-1-k;
            }
        }
        return '.';
    }
};