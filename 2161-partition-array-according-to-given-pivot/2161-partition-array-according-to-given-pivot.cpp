class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> beforePivot;
        vector<int> afterPivot;
        vector<int> ans;
        int sameElement=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                beforePivot.push_back(nums[i]);
            }else if(nums[i]>pivot){
                afterPivot.push_back(nums[i]);
            }else{
                sameElement++;
            }
        }

        for(int i=0;i<beforePivot.size();i++){
            ans.push_back(beforePivot[i]);
        }
        while(sameElement--){
            ans.push_back(pivot);
        }
        for(int i=0;i<afterPivot.size();i++){
            ans.push_back(afterPivot[i]);
        }

        return ans;
    }
};