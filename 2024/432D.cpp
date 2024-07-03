// link: https://codeforces.com/problemset/problem/432/D D. Prefixes and Suffixes
// time: 2024/7/2 18:33:21 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
template <class T> istream &operator>> (istream &cin,  vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl           '\n'
#define print(...)     cout << format(__VA_ARGS__)
#define println(...)   cout << format("{0}\n", __VA_ARGS__)
struct _INIT_IO_END { _INIT_IO_END() { cout << fixed << setprecision(   15   );  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 
#ifdef  LOCAL //  dbg
#include "algo/dbg.h"
#else
#define dbg(...)    ;
#define eprint(...) ;
#endif
auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on


// -------------------------------------------------------------------

// z[x] 计算 s[x:] 和 s[0:] 的最长公共前缀的长度，z[0] = 0。（例如 abacaba -> 0010301）。 O(n) 复杂度
vector<int> Z(const string &S) {
   vector<int> z(int(S.size()));
   int l = -1, r = -1;
   for (int i = 1; i < int(S.size()); i++) {
      z[i] = i > r ? 0 : min(r - i, z[i - l]);
      while (i + z[i] < int(S.size()) && S[i + z[i]] == S[z[i]]) {
         z[i]++, l = i, r = i + z[i];
      }
   }
   return z;
}

auto solve() -> void {
   
   string s;
   cin >> s;
   const int n = int(s.size());
   vector<int> z = Z(s);
   
   vector<int> tmp = z;
   ranges::sort(tmp);
   
   vector<pair<int, int>> ans;
   for (int i = n - 1; i >= 0; i--) {
      if (z[i] == n - i) {
         int cnt = n - int(lower_bound(tmp.begin(), tmp.end(), z[i]) - tmp.begin()) + 1;
         ans.push_back({z[i], cnt});
      }
   }
   ans.push_back({n, 1});

   println(int(ans.size()));
   for (auto& [left, cnt] : ans) {
      print("{} {}\n", left, cnt);
   }

   return;
}

// -------------------------------------------------------------------
