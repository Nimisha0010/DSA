class Solution {
public:
    vector<string> ans;
    unordered_map<char , string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    void solve(string &digits, int idx , string curr ){
        if(idx == digits.size()){
            ans.push_back(curr);
            return ;
        }
        string letters = mp[digits[idx]];
        for( char ch : letters){
            curr.push_back(ch);
            solve(digits, idx + 1, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
           return {};
        solve (digits,0,"");
        return ans;      
    }
};