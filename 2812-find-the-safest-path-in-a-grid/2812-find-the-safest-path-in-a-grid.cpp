class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        /// bfs call manthaan distances
        while(!q.empty()){
            int curr_row=q.front().first;
            int curr_col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = dx[i]+curr_row;
                int ncol = dy[i]+curr_col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && dist[nrow][ncol]==INT_MAX){
                     dist[nrow][ncol]= dist[curr_row][curr_col]+1;
                     q.push({nrow,ncol});
                }
            }
        }
            // bfs call for the answer 
            int ans=0;
            priority_queue<pair<int,pair<int,int>>> pq;
            vector<vector<int>> visited(n,vector<int>(n,0));
            pq.push({dist[0][0],{0,0}});
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int val = it.first;
                int row=  it.second.first;
                int col = it.second.second;
                if(visited[row][col]==1)continue;
                visited[row][col]=1;
                
                if(row==n-1 && col==n-1)return val;
                for(int i=0;i<4;i++){
                    int nrow = dx[i]+row;
                    int ncol = dy[i]+col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && visited[nrow][ncol]!=1){
                        pq.push({min(val,dist[nrow][ncol]),{nrow,ncol}});
                    }
                }
            }
        return 0;
    }
};