class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128,-1);
        int left=0 , ans=0;
        for(int right =0; right < s.size();right++){
            left=max(left,lastIndex[s[right]] + 1);
            lastIndex[s[right]] = right;
            ans=max(ans,right - left + 1);
        }
        return ans;
    }
};