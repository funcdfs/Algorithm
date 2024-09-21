// link: https://codeforces.com/contest/567/problem/A A. Lineland Mail
// time: 2024/9/21 13:41:12 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'	 /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)	std::cout << __VA_ARGS__ 			  /* C++23 std::print()	-> the format string is printed to the standard output */ 
#define println(...) std::cout << __VA_ARGS__ << '\n' /* C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { std::cout << fixed << setprecision(		15		/* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

void solve(); /* main --> */ int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs	// clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


void solve() {
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;

   // 数轴上有 n 个点，给出每个点的横坐标（保证从小到大排序），求每个点到其他点的最小距离和最大距离。

   cout << abs(a[1]-a[0]) << ' ' << abs(a.back()-a[0]) << endl;
   for (int i = 1; i < n-1; i++) {
      if (abs(a[i-1] - a[i]) < abs(a[i+1] - a[i])) {
         cout << abs(a[i-1] - a[i]);
      } else {
         cout << abs(a[i+1] - a[i]);
      }
      cout << ' ';
      if (abs(a[0] - a[i]) < abs(a.rbegin()[0] - a[i])) {
         cout << abs(a.back() - a[i]);
      } else {
         cout << abs(a[0] - a[i]);
      }
      cout << endl;
   }

   cout << abs(a.rbegin()[1]-a.back()) << ' ' << abs(a.at(0)-a.back()) << endl;
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
