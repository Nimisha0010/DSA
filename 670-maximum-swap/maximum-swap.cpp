class Solution {
public:
    int maximumSwap(int num) {
    string s = to_string(num), result = s;
    for(int i=0;i<s.size();i++) for(int j=i+1;j<s.size();j++) swap(s[i],s[j]), result=max(result,s), swap(s[i],s[j]);
    return stoi(result);
    }
};