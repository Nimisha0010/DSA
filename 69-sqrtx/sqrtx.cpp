class Solution {
public:
    int mySqrt(int x) {
        long long n = 0, r = x, m;
        while (n <= r) {
            m = n + (r - n) / 2;
            if (m * m <= x) n = m + 1;
            else r = m - 1;
        }
        return r;
    }
};