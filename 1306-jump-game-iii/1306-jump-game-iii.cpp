class Solution {
public:
    bool fun(vector<int>& arr,int i,vector<int>& visited,int n){
        if(i==n)return false;
        if(arr[i]==0)return true;
        if(visited[i]==true)return false;
        int forward_jump = arr[i]+i;
        int backward_jump = i-arr[i];
        bool f=false;
        bool b=false;
        if(forward_jump<n && visited[forward_jump]!=1){
            visited[i]=1;
            f= fun(arr,forward_jump,visited,n);
        }
        if(backward_jump>=0 && visited[backward_jump]!=1){
            visited[i]=1;
            b= fun(arr,backward_jump,visited,n);
        }
        return f||b;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n,0);
        return fun(arr,start,visited,n);
    }
};