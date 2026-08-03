class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int tr1 = INT_MIN;
            int tr2 = INT_MIN;
            int tr3 = INT_MIN;

            tr1 = stoneValue[i] - dp[i+1];
            if(i+1 < n)
               tr2 = stoneValue[i] + stoneValue[i+1] - dp[i+2];
            if(i+2 < n)
                tr3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
            dp[i] = max(tr1,max(tr2,tr3));
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};