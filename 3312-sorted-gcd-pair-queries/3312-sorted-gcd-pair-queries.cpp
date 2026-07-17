class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_gcd = *max_element(nums.begin(),nums.end());
        vector<int> freq(max_gcd+1,0);
        for(int n:nums){
            freq[n]++;
        }

        for(int i=1;i<=max_gcd;i++){
            int sum =0;
            for(int j=i;j<=max_gcd;j+=i){
                sum+=freq[j];
            }
            freq[i]=sum;
        }

        for(int i=1;i<=max_gcd;i++){
            freq[i]= (1LL* freq[i] * (freq[i]-1))/2;
        }

        for(int i=max_gcd;i>=1;i--){
            int temp =0;
            for(int j=i+i;j<=max_gcd;j+=i){
                temp += freq[j];
            }
            freq[i]-=temp;
        }
        // prefix 
        int sum=0;
        for(int i=1;i<=max_gcd;i++){
            sum+=freq[i];
            freq[i]=sum;
        }
        vector<int> result;
        for(int q:queries){
            int g = lower_bound(freq.begin(),freq.end(),q+1)-freq.begin();
            result.push_back(g);
        }
        return result;
    }
};