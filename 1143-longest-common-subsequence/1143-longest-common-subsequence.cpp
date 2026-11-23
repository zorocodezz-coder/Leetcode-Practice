class Solution {
public:
    int fun(string &text1, string &text2, int i ,int j,vector<vector<int>>& dp){
        if(i>=text1.size() || j>=text2.size())return 0;
        int take=0;
        int not_take1=0;
        int not_take2=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            take = 1+ fun(text1,text2, i+1, j+1,dp);
        }
        not_take1 = fun(text1, text2, i+1,j,dp);
        not_take2 =fun(text1,text2,i,j+1,dp);

        return dp[i][j]= max({take,not_take1,not_take2});

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,-1));
       return fun(text1, text2, 0,0,dp);
    }
};