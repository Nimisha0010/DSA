class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxval = *max_element(nums.begin(), nums.end());

        vector<long long> freq(maxval + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(maxval + 1, 0);
        for (int d = 1; d <= maxval; d++) {
            for (int j = d; j <= maxval; j += d) {
                cnt[d] += freq[j];
            }
        }
        vector<long long> exactPairs(maxval + 1, 0);
        for (int d = maxval; d >= 1; d--) {

            long long c = cnt[d];
            exactPairs[d] = c * (c - 1) / 2;

            for (int j = 2 * d; j <= maxval; j += d)
                exactPairs[d] -= exactPairs[j];
        }
        vector<long long> prefix(maxval + 1, 0);
        for (int i = 1; i <= maxval; i++)
            prefix[i] = prefix[i - 1] + exactPairs[i];

        vector<int> ans;
        for (long long k : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), k + 1) - prefix.begin();
            ans.push_back(g);
        }
        return ans;
    }
};