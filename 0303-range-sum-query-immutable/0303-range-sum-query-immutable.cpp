class NumArray {
public:

    // build a segment tree
    vector<int> segmentTree;
    int n;

    void buildTree(int i,int l, int r,vector<int>& nums){
        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildTree(2*i+1,l,mid,nums);
        buildTree(2*i+2,mid+1,r,nums);
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
        return;
    }
    int Query(int left,int right,int i,int start, int end){
        if(left>end || right< start){
            return 0;
        }
        if(start>=left && right>=end){
            return segmentTree[i];
        }
        int mid = start+(end-start)/2;
        return Query(left,right,2*i+1,start,mid)+Query(left,right,2*i+2,mid+1,end);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n,0);
        buildTree(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return Query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */