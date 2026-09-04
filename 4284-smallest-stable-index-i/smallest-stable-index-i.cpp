class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf(n,0);
        int a = INT_MAX;
        for(int i = n-1; i>=0;i--){
            a=min(a,nums[i]);
            suf[i]=a;
        }
        int b=0;
        for(int i =0;i<n;i++){
            b=max(b,nums[i]);
            int sc=b-suf[i];
            if(sc<=k)return i;
        }
        return -1;
    }
};