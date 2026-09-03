class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min1=INT_MAX,odd=0;
        for (int x : nums1) {
            odd += x & 1;
            min1 = min(min1,x);
        }
        return min1 & 1|| odd == 0;
    }
};