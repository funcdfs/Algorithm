// link: https://www.luogu.com.cn/problem/P3375 P3375 【模板】KMP
// time: 2024/7/2 19:49:57 https://github.com/funcdfs

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

// max len of ( s[0:k-1] == s[i-(k-1):i] ) time: O(N) eg: "aabaaab" 0 1 0 1 2 2 3
vector<int> construct_prefix(string s) {
   const int n = int(s.size());
   vector<int> pi(n);
   for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && s[i] != s[j]) {
         j = pi[j - 1];
      }
      if (s[i] == s[j]) {
         j++;
      }
      pi[i] = j;
   }
   return pi;
}

// KMP: 求出模式串 pattern 在字符串 text 中所有出现的位置的起始下标 time: O(N+M) space: O(N)
vector<int> find_occurrences(string text, string pattern) {
   string cur = pattern + '#' + text;
   int sz1 = int(text.size()), sz2 = int(pattern.size());
   vector<int> v;
   vector<int> lps = construct_prefix(cur);
   for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
      if (lps[i] == sz2) {
         v.push_back(i - 2 * sz2);
      }
   }
   return v;
}

// -------------------------------------------------------------------
auto solve() -> void {
   string s1, s2;
   cin >> s1 >> s2;
   auto kmp = find_occurrences(s1, s2);
   for (auto &x : kmp) {
      cout << x+1 << endl;
   }
   auto prefix = construct_prefix(s2);
   cout << prefix << endl;

   return;
}

// -------------------------------------------------------------------
