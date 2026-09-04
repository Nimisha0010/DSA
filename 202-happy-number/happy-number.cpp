class Solution {
public:
    bool isHappy(int n) {
        set<int> sn;
        int ct=0;
        while(1){
            string s =to_string(n);
            long long num = 0;
            if(sn.contains(n)) break;
            sn.insert(n);
            for(int i=0;i<s.size();i++)
              num+=((s[i]-'0')*(s[i]-'0'));
            n=num;
        }
        return (n==1);
    }
};