// link: https://codeforces.com/contest/1304/problem/B B. Longest Palindrome
// time: 2024/6/27 15:46:15 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std;
using int32   = int32_t;    using int64   = long long;            using int128  = __int128;
using uint32  = unsigned;   using uint64  = unsigned long long;   using rune    = int32;
using float32 = double;     using float64 = long double;          using byte    = char;
istream &operator>>(istream &cin, int128 &x) { x = 0; static string s; cin >> s; for (char &c : s) { x = x * 10 + (c - '0'); } return cin; }
ostream &operator<<(ostream &cout, int128 x) { static char s[60]; int tp = 1; s[0] = '0' + char(x % 10); while(x /= 10) { s[tp++] = '0' + char(x % 10); } while(tp--) {cout << s[tp]; } return cout; }
struct __fastIO {__fastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }} ___fastIO; 
template <class T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) { cin >> x; } return cin; }
template <class T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x : a) { cin >> x; } return cin; }
template <class T1, class T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout << a.first << ' ' << a.second; }
template <class T1, class T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) { for (auto &x : a) { cout << x << '\n'; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, vector<T1> a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, const valarray<T1> &a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, const vector<valarray<T1>> &a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, const vector<vector<T1>> &a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T1> basic_string<T1> operator*(const basic_string<T1> &s, int m) { auto r = s; m *= int(s.size()); r.resize(m); for (int i = int(s.size()); i < m; i++) { r[i] = r[i - s.size()]; } return r; }

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) ;
#endif
#define endl          '\n'
#define print(...)    cout << format(__VA_ARGS__)
#define println(...)  cout << format("{0}\n", __VA_ARGS__)
auto solve() -> void; auto main() -> int32 { solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// -------------------------------------------------------------------
auto solve() -> void {
   int n = 0, m = 0;
   cin >> n >> m;

   vector<string> g(n, "");
   cin >> g;

   unordered_map<string, int> hs;
   for (auto &s : g) {
      hs[s] += 1;
   }
   // dbg(hs);
   vector<string> ansLeft, ansRight;
   string ansMid = "";
   int maxMidLen = 0;
   int64 len = 0;

   for (auto &[k, v] : hs) {
      string rev = k;
      reverse(rev.begin(), rev.end());
      if (hs.contains(rev) && rev != k) {
         int cnt = min(hs[rev], hs[k]);
         for (int i = 0; i < cnt; i++) {
            ansLeft.push_back(k);
            ansRight.push_back(rev);
            len += int64(2) * int64(k.size());
         }
         hs[k] -= cnt;
         hs[rev] -= cnt;
         if (hs[k] == 0) {
            hs.erase(k);
         }
         if (hs[rev] == 0) {
            hs.erase(rev);
         }
      }
      if (rev == k) {
         int cnt = v / 2;
         for (int i = 0; i < cnt; i++) {
            ansLeft.push_back(k);
            ansRight.push_back(k);
            len += int64(2) * int64(k.size());
         }
         hs[k] -= cnt * 2;
         if (hs[k] == 0) {
            hs.erase(k);
         }
      }
      if (hs.contains(k) && rev == k) {
         assert(v == 1);
         if (int(k.size()) > maxMidLen) {
            maxMidLen = int(k.size());
            ansMid = k;
         }
      }
   }
   println(len + int64(ansMid.size()));
   for (int i = 0; i < int(ansLeft.size()); i++) {
      cout << ansLeft[i];
   }
   cout << ansMid;
   for (int i = 0; i < int(ansRight.size()); i++) {
      cout << ansRight[int(ansRight.size()) - i - 1];
   }
   cout << endl;
}

// -------------------------------------------------------------------
