class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        int obvious = n * (n + 1) / 2;
        int reality = 0;
        for (int num : nums)
            reality += num;
        return obvious - reality;
    }
};