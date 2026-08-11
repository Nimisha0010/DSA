class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int sk = 0, curr = x;
                while (st.find(curr) != st.end()) {
                    sk++;
                    curr++;
                }
                res = max(res, sk);
            }
        }
        return res;
    }
};