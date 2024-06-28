// link: https://codeforces.com/contest/1916/problem/C C. Training Before the Olympiad

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
#define printx(...)   cout << format("{} ", __VA_ARGS__)
#define println(...)  cout << format("{0}\n", __VA_ARGS__)
auto solve(int _case) -> void; auto main() -> int32 { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on


// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;
   
   // a[i], a[j] -> insert ((a[i]+a[j]) / 2) * 2 
   // A 希望留下来的最大，B 希望留下来的最小，ABABAB，剩余 1 个的时候停止。
   
/*
想使答案大的人
   选择两个偶数和两个奇数，那么答案不会减小. 
   在可以选择两个奇数时，绝对不会选择两个偶数，因为这样可以让想使答案小的人可以选择的奇数变少。
   if odd >= 2:
      odd -= 2
想使答案小的人
   如果选择了一个奇数一个偶数，那么答案会减小一。(偶数公用，奇数对变小有作用)
   if odd >= 1:
      odd -= 1

if odd >= 3:
   odd -= 3, ans -= 1
   ans -= (odd / 3)

然后单独考虑 odd % 3 之后的余数，0 不变，1 少一，2 不变
*/
   int64 sum = 0, odd = 0;
   for (int i = 0; i < n; i++) {
      sum += a[i];
      odd += a[i] % 2;
      if (i == 0) {
         print("{} ", sum);
      } else {
         int64 ans = sum - odd / 3;
         if (odd % 3 == 1) {
            ans -= 1;
         } // 0. 1(-). 2
         print("{} ", ans);
      }
   }
   println(""); 


   return;
}
// -------------------------------------------------------------------
