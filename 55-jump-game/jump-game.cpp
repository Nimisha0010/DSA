class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxr=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i>mxr) return false;
        mxr=max(mxr,i+nums[i]);
        if(mxr>=n-1) return true;
        }
        return true;
    }
};