// link: https://codeforces.com/contest/1800/problem/B B. Count the Number of Pairs
// time: 2024/7/2 16:48:07 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n' /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)  cout << format(__VA_ARGS__) /* the format string is printed to the standard output */ 
#define println(...) cout << format("{0}\n", __VA_ARGS__); /* print single value and appends a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* for local debugging purposes */ 
#include "algo/dbg.h"
#else /* link of dbg.h: https://gist.github.com/funcdfs */
#define dbg(...)    ; /* dbg(any); */
#define eprint(...) ; /* eprint("{} {}\n", x, y);*/
#endif

auto solve(int _case) -> void; int32 main() {       int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0, k = 0;
   cin >> n >> k;
   string s;
   cin >> s;

   unordered_map<char, int> hs;
   for (int i = 0; i < n; i++) {
      hs[s[i]] += 1;
   }
   int ans = 0;
   for (char c = 'a'; c <= 'z'; c++) {
      int lenBig = hs[c + ('A' - 'a')];
      int lenSmall = hs[c];
      eprint("{} {} {}, k={}\n", c, lenBig, lenSmall, k);
      int diff = abs(lenBig - lenSmall) / 2;
      ans += min(lenBig, lenSmall);
      if (k >= diff) {
         k -= diff;
         ans += diff;
      } else {
         ans += k;
         k = 0;
      }
   }
   println(ans);
   return;
}

// -------------------------------------------------------------------
