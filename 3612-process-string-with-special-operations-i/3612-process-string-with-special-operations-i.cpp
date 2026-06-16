class Solution {
public:
    string processStr(string s) {
        string temp="";
        for(char &c:s){
            if(c>='a' && c<='z'){
                temp+=c;
            }
            if(c=='*'){
                if(temp.size()>0){
                    temp.pop_back();
                }
            }
            if(c=='#'){
                temp = temp+temp;
            }
            if(c=='%'){
                reverse(temp.begin(),temp.end());
            }
        }
        return temp;
    }
};