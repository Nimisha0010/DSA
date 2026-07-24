class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=0;
        int count=0;
        for(int x : nums){
            if(count==0)
              cand = x;
            if(x == cand)
               count++;
            else
               count--;
        }
        return cand;
    }
};