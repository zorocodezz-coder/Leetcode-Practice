class Solution {
public:
// tc = n log m+ n log n
// sc = O(n)

// n*log(m)
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n =nums.size();

        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        vector<int> prefixGcd(n,0);
        for(int i=0;i<n;i++){
            prefixGcd[i]=gcd(prefix[i],nums[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end()); // nlong n 
        int l=0;
        int r=n-1;
        long long sum=0;
        while(l<r){
            sum+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};