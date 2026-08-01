class Solution {
public:
    string route(string stg) {
        stack<char> st;
        for (char ch : stg) {
            if (ch == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(ch);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return route(s) == route(t);
    }
};