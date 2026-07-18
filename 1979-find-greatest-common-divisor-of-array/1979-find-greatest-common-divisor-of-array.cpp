class Solution {
public:
    int fun_gcd(int a,int b){ // o(log M)
        if(b==0)return a;
        return fun_gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(),nums.end()); // o(n)
        int gratest = *max_element(nums.begin(),nums.end()); // o(n)

        return fun_gcd(smallest,gratest);

        // tc = o(n)
        // sc = o(1)
    }
};