class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> A1,A2;
        A1.push_back(nums[0]);
        A2.push_back(nums[1]);
        for (int i=2;i<n;i++) {
            if (A1.back()>A2.back()) {
                A1.push_back(nums[i]);
            } else {
                A2.push_back(nums[i]);
            }
        }
        A1.insert(A1.end(),A2.begin(),A2.end());
        return A1;
    }
};