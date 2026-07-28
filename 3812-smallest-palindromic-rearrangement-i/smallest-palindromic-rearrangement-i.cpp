class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char c : s)
            freq[c - 'a']++;
            string FH = "";
            char mid =0;
            for(int i = 0;i<26;i++){
                if(freq[i]%2){
                  mid = char('a' + i);
                }
                FH.append(freq[i]/2 , char('a' + i));
            }
            string SH = FH;
            reverse(SH.begin(),SH.end());
            if(mid)
              return FH + string(1,mid) + SH;
        return FH + SH;
    }
};