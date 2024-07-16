// link: https://codeforces.com/contest/1690/problem/E E. Price Maximization
// time: 2024/7/9 12:24:14 https://github.com/funcdfs

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

auto solve(int _case) -> void; int32 main() {       int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

#include <ext/pb_ds/assoc_container.hpp>   // Common file
#include <ext/pb_ds/tree_policy.hpp>       // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using MultiTree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
If using MultiTree:
   Ranking of x:                                                 mt.order_of_key(x) + 1
   Find the number with rank idx:                                *mt.find_by_order(idx)
   To delete only one of multiple identical numbers:             mt.erase(st.upper_bound(x));
   Predecessor is defined as the largest number less than x:     *--mt.upper_bound(x)
   Successor is defined as the smallest number greater than x:   *mt.lower_bound(x)
*/
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> a(n, 0);
   cin >> a;

   // (a[i] + a[j]) / 2 == value
   // MultiTree<int> s;
   multiset<int> s; 
   int64 ans = 0;
   for (int i = 0; i < n; i++) {
      ans += a[i] / k;
      a[i] %= k;
      s.insert(a[i]);
   }

   while (!s.empty()) {
      int x = *s.begin();
      s.erase(s.begin());
      auto it = s.lower_bound(k - x);   // first k-x <= value
      if (it != end(s)) {
         s.erase(it);
         ans += 1;
      }
   }

   cout << ans << endl;

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
