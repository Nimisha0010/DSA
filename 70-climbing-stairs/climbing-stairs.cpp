class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
          return n;
        int ft= 1,sd=2;
        for(int i=3;i<=n;i++){
            int td=ft + sd;
               ft = sd;
               sd = td;
        }
        return sd;
    }
};