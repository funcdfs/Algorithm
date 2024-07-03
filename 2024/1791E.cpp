// link: https://codeforces.com/contest/1791/problem/E E. Negatives and Positives
// time: 2024/6/30 19:17:57 https://github.com/funcdfs

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
auto solve(int _case) -> void; auto main() -> int32 { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

const float64 EPS = 1e-6; 
const int32 MOD = 1e9 + 7;
// const int32 MOD = 998244353;
const int32 INF = 0x3f3f3f3f;
const int64 INF_64 = 0x3f3f3f3f3f3f3f3fll;

// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;

   function<bool(int &, int &)> minPQCmp = [](int &i1, int &i2) {
      return i1 > i2;
   };   // 弹出元素是最小值
   priority_queue<int, vector<int>, function<bool(int &, int &)>> minPQ(minPQCmp);

   for (int i = 0; i < n; i++) {
      minPQ.push(a[i]);
   }
   sort(a.begin(), a.end());
   dbg("init", a);

   while (true) {
      int x = minPQ.top();
      minPQ.pop();
      int y = minPQ.top();
      minPQ.pop();
      int val = x + y;
      if (val >= 0) {
         minPQ.push(x);
         minPQ.push(y);
         break;
      } else {
         minPQ.push(-x);
         minPQ.push(-y);
      }
   }
   a.clear();
   while (minPQ.size()) {
      a.push_back(minPQ.top());
      minPQ.pop();
   }
   int64 sum = accumulate(a.begin(), a.end(), int64(0));

   println(sum);
   dbg("final", a);

   return;
}

// -------------------------------------------------------------------
