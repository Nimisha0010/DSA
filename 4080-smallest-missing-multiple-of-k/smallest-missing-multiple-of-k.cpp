class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> miss(nums.begin(),nums.end());
        int result =k;
        while(miss.count(result)){
            result+=k;
        }
        return result;
    }
};