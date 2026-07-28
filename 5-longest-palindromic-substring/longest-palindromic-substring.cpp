class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2)
            return s;
        int st= 0;
        int mxLen = 1;
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i, st, mxLen);      
            expand(s, i, i + 1, st, mxLen);   
        }
        return s.substr(st, mxLen);
    }
private:

    void expand(string &s, int left, int right, int &st, int &mxLen) {
        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }
        int len = right - left - 1;
        if (len > mxLen) {
            mxLen = len;
            st = left + 1;
        }
    }
};