class Solution {
public:
    int minimumPushes(string word) {
        int result  = 0 , n = word.length();
        for(int i =0; i<n;i++){
            result  +=(i/8)+1;
        }
        return result;
    }
};