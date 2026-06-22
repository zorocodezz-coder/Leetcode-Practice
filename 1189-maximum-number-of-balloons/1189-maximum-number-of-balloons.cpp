class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string str="balloon";
        vector<int> letters(26,0);
        for(char &c:text){
            letters[c-'a']++;
        }
        int occur=INT_MAX;
        for(char &c:str){
            if(c=='l' || c=='o'){
                occur = min(occur,letters[c-'a']/2);
            }else occur = min(occur,letters[c-'a']);
        }
        return occur;
    }
};