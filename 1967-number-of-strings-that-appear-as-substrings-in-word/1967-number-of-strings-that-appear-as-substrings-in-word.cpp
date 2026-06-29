class Solution {
public:
    int fun(string& pat, string& word) {
        int m = pat.size();
        int n = word.size();

        vector<int> lps(m, 0);
        int i = 1, j = 0;
        while (i < m) {
            if (pat[i] == pat[j]) {
                lps[i] = j + 1;
                i++;
                j++;
            } else {
                if (j == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    j = lps[j - 1];  
                }
            }
        }

        
        int count = 0;
        i = 0; 
        j = 0; 
        while (i < n) {
            if (word[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m) {        
                count++;
                j = lps[j - 1];    
            } else if (i < n && word[i] != pat[j]) {
                if (j == 0) i++;   
                else j = lps[j - 1];
            }
        }
        return count;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (auto& str : patterns) {
            if (fun(str, word) > 0) 
                count++;
        }
        return count;
    }
};