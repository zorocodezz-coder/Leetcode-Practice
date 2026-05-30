class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>> q;
        set<int> visited;
        q.push({x,0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto [val,step] = q.front();
                q.pop();
                if(visited.count(val)!=0){
                    continue;
                }
                visited.insert(val);
                if(val==y)return step;

                q.push({val+1,step+1});
                q.push({val-1,step+1});
                if(val%11==0)
                {
                    q.push({val/11,step+1});
                }
                if(val%5==0)
                {
                    q.push({val/5,step+1});
                }
            }
        }
        return -1;
    }
};