class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        // generate all substring from word
        unordered_set<string> allSubstring;
        
        for(int i=0;i<word.size();i++){
            string temp="";
            for(int j=i;j<word.size();j++){
                temp+=word[j];
                allSubstring.insert(temp);
            }
        }
        int count=0;
        for(string s:patterns){
            if(allSubstring.count(s)>0){
                count++;
            }
        }
        return count;
    }
};