class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> s;
        for (int i=0;i<digits.size();i++) {
            for (int j=0;j<digits.size();j++) {
                for (int k=0;k<digits.size();k++) {
                    if (i==j || j==k || i==k)continue;
                    int a=digits[i];
                    int b=digits[j];
                    int c=digits[k];
                    if (a==0 || c%2!=0)continue;
                    int num=100*a+10*b+c;
                    s.insert(num);
                }
            }
        }
        return s.size();
    }
};