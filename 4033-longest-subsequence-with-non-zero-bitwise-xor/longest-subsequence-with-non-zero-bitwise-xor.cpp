class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int TX=0;
        bool AZ = true;
         for(int x : nums){
            TX ^= x;
            if(x>0){
                AZ = false;
            }
         }
         if(TX>0){
            return n ;
         }
         return AZ?0:n-1;
    }
};