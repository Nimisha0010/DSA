class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 0;
        unordered_map<int,int> freq;
        for(int i=0,j=0;j<n;j++){
            int &count = freq[nums[j]];
            count++;
            while(count > k){
                freq[nums[i++]]--;
            }
            curr = max(curr,j-i+1);
        }
        return curr;
    }
};