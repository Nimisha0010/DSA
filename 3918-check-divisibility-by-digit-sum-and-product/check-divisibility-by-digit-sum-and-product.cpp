class Solution {
public:
    bool checkDivisibility(int n) {
        int og =n;
        int sum=0;
        int prod=1;
        while(n>0){
           int dg=n%10;
            sum+=dg;
            prod*=dg;
            n/=10;
        }
        return (og % (sum+prod)==0);
    }
};