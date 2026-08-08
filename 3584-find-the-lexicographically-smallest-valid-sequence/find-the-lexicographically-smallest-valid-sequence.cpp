class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> last(n, -1);
        int j = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }
        vector<int> res;
        int skip = 0;
        j = 0;
        for (int i = 0; i < m && j < n; i++) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            }
            else if (skip == 0 &&
                     (j == n - 1 || last[j + 1] > i)) {
                res.push_back(i);
                skip++;
                j++;
            }
        }
        return j == n ? res : vector<int>();
    }
};