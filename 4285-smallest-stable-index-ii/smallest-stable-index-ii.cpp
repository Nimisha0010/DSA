class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(),max1=nums[0];
        vector<int> min1(n);
        min1[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) min1[i]=min(nums[i],min1[i+1]);
        for(int i=0;i<n;i++){
            max1=max(max1,nums[i]);
            if(max1-min1[i]<=k) return i;
        }
        return -1;
    }
};