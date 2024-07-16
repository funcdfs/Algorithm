// link: https://codeforces.com/contest/701/problem/C C. They Are Everywhere
// time: 2024/7/9 12:40:35 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'    /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)   cout << format(__VA_ARGS__)           /* the format string is printed to the standard output */ 
#define println(...) cout << format("{0}\n", __VA_ARGS__); /* to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

#include <ext/pb_ds/assoc_container.hpp>   // Common file
#include <ext/pb_ds/tree_policy.hpp>       // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

auto solve() -> void {
   int n = 0;
   cin >> n;
   string s(n, ' ');
   cin >> s;

   // 长度最小的区间，包含字符串中的所有字母（区分大小写）

   unordered_set<char> hs;
   for (auto& c : s) hs.insert(c); 

   int ans = n;
   unordered_map<char, int> now; 
   for (int i = 0, r = 0; i < n; i++) {
      while (r < n && now.size() < hs.size()) {
         now[s[r]] += 1; 
         r += 1; 
      }
      if (now.size() == hs.size()) {
         ans = min(ans, r-i); 
      }
      now[s[i]] -= 1; 
      if (now[s[i]] == 0) {
         now.erase(s[i]); 
      }
   }
   cout << ans << endl; 

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
