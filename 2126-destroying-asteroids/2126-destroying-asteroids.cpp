class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long volume = mass;
        for(int &ast:asteroids){
            if(volume<ast)return false;
            volume +=ast;
        }
        return true;
    }
};