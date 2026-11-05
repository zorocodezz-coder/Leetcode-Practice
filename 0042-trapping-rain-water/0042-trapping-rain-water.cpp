class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax;
        vector<int> rmax;
        int n =height.size();
        int max_l=0;
        for(int i=0;i<n;i++){
            max_l=max(max_l,height[i]);
            lmax.push_back(max_l);
        }
        int max_r=0;
        for(int j=n-1;j>=0;j--){
            max_r=max(max_r,height[j]);
            rmax.push_back(max_r);
        }
        reverse(rmax.begin(),rmax.end());
        int total=0;
        for(int i=0;i<n;i++){
            total += min(rmax[i],lmax[i])-height[i];
        }
        return total;
    }
};