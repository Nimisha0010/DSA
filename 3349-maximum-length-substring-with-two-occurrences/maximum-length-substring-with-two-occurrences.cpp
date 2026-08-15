class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res =0;
        for(int l = 0;l<n;l++){
            array<int,26> ct{};
            for(int r =l;r<n;++r){
                 int idx =s[r] - 'a';
                ++ct[idx];
                if(ct[idx]>2){
                    break;
                }
                res=max(res,r - l+1);
            }
        }
        return res;
    }
};