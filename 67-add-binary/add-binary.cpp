class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length()-1;
        int m = b.length()-1;
        int carry = 0;
        string result;

        while(n >= 0||m >= 0||carry){
            int sum = carry ;
            if(n >= 0)
              sum += a[n--]-'0';
            if(m >= 0)
              sum += b[m--]-'0';
            result += char((sum % 2)+'0');
            carry = sum / 2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};