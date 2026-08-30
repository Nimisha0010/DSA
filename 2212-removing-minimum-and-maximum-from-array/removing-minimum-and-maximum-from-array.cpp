class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx=0;
        int maxIdx=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[minIdx]){
                minIdx=i;
            }
            if(nums[i]>nums[maxIdx]){
                maxIdx=i;
            }
        }
        int l = min(minIdx,maxIdx);
        int r = max(minIdx,maxIdx);
        int front= r+1;
        int back = n-l;
        int both = (l+1)+(n-r);
        return min({front,back,both});
    }
};