class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        // i should take start and end
        int dx[8]={-2,-2,-1,1,2,2,1,-1};
        int dy[8]={-1,1,2,2,1,-1,-2,-2};
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        bool visited[8][8][2]={};
        visited[start[0]][start[1]][0]=true;
        int moves=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x==target[0] && y ==  target[1] && moves%2==0)return true;
            for(int i=0;i<8;i++){
                int nx = dx[i]+x;
                int ny = dy[i]+y;

                if(nx>=0 && nx<8 && ny>=0 && ny<8 && !visited[nx][ny][(moves+1)%2] ){
                    visited[nx][ny][(moves+1)%2]=true;  
                    q.push({nx,ny});
                }
            }            
            }
            moves++;
        }
        return false;
    }
};