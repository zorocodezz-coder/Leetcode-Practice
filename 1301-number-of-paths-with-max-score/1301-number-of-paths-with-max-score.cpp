class Solution {
public:
    const int MOD = 1e9+7;
    int n;

    // tc // no. of branch 3 , each time choice select or not sect
    // 3^(2*n)
    // 3^200 = 2.6* 10^95 // 10^8<

    pair<int,int> dp[105][105];
    bool vis[105][105];

    pair<int,int> fun(vector<string>& board,int i ,int j){
        if(i<0 || j<0 || board[i][j]=='X'){
            return {-1,0};
        }
        if(i==0 && j==0){
            return {0,1};
        }

        if(vis[i][j]){
            return dp[i][j];
        }

        vis[i][j]=true;

        auto up = fun(board,i-1,j);
        auto left = fun(board,i,j-1);
        auto diag = fun(board,i-1,j-1);

        int best  = max({up.first,left.first,diag.first});

        if(best==-1){
            return dp[i][j]={-1,0};
        }

        long long ways=0;
        if(up.first==best){
            ways+=up.second;
        }
        if(left.first==best){
            ways+=left.second;
        }
        if(diag.first==best){
            ways+=diag.second;
        }
        ways%=MOD;

        int val=0;
        if(isdigit(board[i][j])){
            val=board[i][j]-'0';
        }
        return dp[i][j]={best+val,(int)ways};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        auto ans = fun(board, n-1,n-1);
        if(ans.first==-1){
            return {0,0};
        }
        return {ans.first,ans.second};
    }
};