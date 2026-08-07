class Solution {
public:
  string smallestNumber(string num, long long t) {
    auto [need, ok] = primesOfT(t);
    if (!ok) return "-1";

    D8 needD = toDigits(need);
    if (sum(needD) > (int)num.size()) return build(needD);

    P4 pre = primesOfStr(num);
    int firstZero = num.find('0');
    if (firstZero == string::npos) {
      firstZero = num.size();
      if (isSubset(need, pre)) return num;
    }

    for (int i = (int)num.size() - 1; i >= 0; --i) {
      int d = num[i] - '0';
      pre = sub(pre, DP[d]);
      int space = num.size() - 1 - i;
      if (i > firstZero) continue;
      for (int b = d + 1; b < 10; ++b) {
        D8 rest = toDigits(sub(sub(need, pre), DP[b]));
        int s = sum(rest);
        if (s <= space)
          return num.substr(0, i) + char('0' + b) + string(space - s, '1') + build(rest);
      }
    }

    D8 ext = toDigits(need);
    return string(num.size() + 1 - sum(ext), '1') + build(ext);
  }

private:
  using P4 = array<int, 4>;  // exponents of primes {2, 3, 5, 7}
  using D8 = array<int, 8>;  // counts of digits {2..9}, index i -> digit i+2

  static constexpr array<P4, 10> DP = {{
      {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
      {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
  }};

  pair<P4, bool> primesOfT(long long t) {
    P4 c{};
    int ps[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; ++i)
      while (t % ps[i] == 0) { t /= ps[i]; ++c[i]; }
    return {c, t == 1};
  }

  P4 primesOfStr(const string& s) {
    P4 c{};
    for (char ch : s)
      for (int i = 0; i < 4; ++i) c[i] += DP[ch - '0'][i];
    return c;
  }

  P4 sub(P4 a, const P4& b) {
    for (int i = 0; i < 4; ++i) a[i] = max(0, a[i] - b[i]);
    return a;
  }

  bool isSubset(const P4& a, const P4& b) {
    for (int i = 0; i < 4; ++i) if (a[i] > b[i]) return false;
    return true;
  }

  int sum(const D8& d) { return accumulate(d.begin(), d.end(), 0); }

  D8 toDigits(P4 c) {
    D8 r{};
    r[6] = c[0] / 3; c[0] %= 3;   
    r[7] = c[1] / 2; c[1] %= 2;   
    int c4 = c[0] / 2, c2 = c[0] % 2, c3 = c[1], c6 = 0;
    if (c2 && c3) { c2 = c3 = 0; c6 = 1; }
    if (c3 && c4) { c2 = 1; c6 = 1; c3 = 0; c4 = 0; }
    r[0] = c2; r[1] = c3; r[2] = c4; r[3] = c[2]; r[4] = c6; r[5] = c[3];
    return r;
  }

  string build(const D8& d) {
    string s;
    for (int i = 0; i < 8; ++i) s += string(d[i], '0' + i + 2);
    return s;
  }
};