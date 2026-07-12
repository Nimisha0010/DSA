class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        unordered_map<string, int> target;

        for (string &word : words)
            target[word]++;
        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;
        int n = s.size();

        if (n < totalLen)
            return ans;

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> window;
            int left = offset, count = 0;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if (count == totalWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};