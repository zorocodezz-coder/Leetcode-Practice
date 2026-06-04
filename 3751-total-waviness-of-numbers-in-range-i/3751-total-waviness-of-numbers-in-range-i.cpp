class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            string str = to_string(i);
            if(str.size()<3)continue;
            for(int k=1;k<str.size()-1;k++){
                if(str[k]>str[k-1] && str[k]>str[k+1]){
                    count++;
                }else if(str[k]<str[k-1] && str[k]<str[k+1])
                {
                    count++;
                }
            }
        }
        return count;
    }
};