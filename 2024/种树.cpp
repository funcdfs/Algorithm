// link: https://ac.nowcoder.com/acm/contest/950/B 种树
// time: 2024/6/30 13:08:19 https://github.com/funcdfs

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
   
   struct sug {
      int st; 
      int ed;
      int cnt;
   }; // put cnt on [st, ed]

   int n = 0, h = 0;
   cin >> n >> h;
   vector<sug> s(h);
   for (int i = 0; i < h; i++) {
      cin >> s[i].st >> s[i].ed >> s[i].cnt;
   } // 为满足所有居民的建议，所需要种树的最少数量。

   sort(s.begin(), s.end(), [&](auto& a, auto& b) -> bool {
      return a.ed < b.ed;
   });

   unordered_map<int, int> hs;

   for (int i = 0; i < int(s.size()); i++) {
      int cnt = 0;
      /* for (int x = s[i].st; x <= s[i].ed; x++) {
         if (hs[x] == 1) {
            cnt += 1;
         }
      } */
      // todo 线段树区间求和
      if (cnt < s[i].cnt) {
         int begin = s[i].ed;
         while (cnt < s[i].cnt) {
            if (hs[begin] == 1) continue;
            hs[begin] = 1;
            begin -= 1;
            cnt += 1;
         }
      }
   }

   int ans = 0;
   for (auto& [k, v] : hs) {
      if (v == 1) {
         ans += 1;
      }
   }

   cout << ans;

   
   return;
}
// -------------------------------------------------------------------
