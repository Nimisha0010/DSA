class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        int sg = 1;
        if(i < n &&s[i]=='-'){
            sg = -1;
            i++;
        }else if(i < n && s[i] == '+'){
            i++;
        }
        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num * 10  + (s[i] - '0');
            if(sg == 1 && num > INT_MAX){
              return INT_MAX;
          }
          if(sg == -1 && -num < INT_MIN){
            return INT_MIN;
          }
          i++;
        }
        return (int)(sg * num);
    }
};