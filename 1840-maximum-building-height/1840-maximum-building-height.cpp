class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        int m = restrictions.size();
        if(restrictions[m-1][0]!=n){
            restrictions.push_back({n,n-1});
            m++;
        }

        for(int i=0;i<m-1;i++){
            int id1 = restrictions[i][0];
            int id2 = restrictions[i+1][0];
            int x1 = restrictions[i][1];
            int x2 = restrictions[i+1][1];
            int d = id2-id1;
            restrictions[i+1][1] = min(x2,x1+d);
        }
        for(int i=m-1;i>0;i--){
            int id1 = restrictions[i][0];
            int id2 = restrictions[i-1][0];
            int x1 = restrictions[i][1];
            int x2 = restrictions[i-1][1];
            int d = id1-id2;
            restrictions[i-1][1] = min(x2,x1+d);
        }
        int max_height=0;
        for(int i=0;i<m-1;i++){
            int id1 = restrictions[i][0];
            int id2 = restrictions[i+1][0];
            int x1 = restrictions[i][1];
            int x2 = restrictions[i+1][1];

            int diff = abs(x1-x2);
            if(diff>0){
                if(x1<x2){
                    id1+=diff;
                    int d = (id2-id1)/2;
                    max_height = max(max_height,x2+d);
                }
                else {
                    id2-=diff;
                    int d =(id2-id1)/2;
                    max_height = max(max_height,x1+d);
                }
            }else{
                int d = (id2-id1)/2;
                max_height = max(max_height,x1+d);
            }
        }
        return max_height;

    }
};