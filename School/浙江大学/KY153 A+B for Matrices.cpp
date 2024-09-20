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

auto solve() -> void; /* main --> */ int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

// link: https://www.nowcoder.com/share/jump/2121624911726816224665
// 题意：给出两个同型矩阵A，B（行列数在每组数据第一行给出），判断矩阵A+B全0行和全0列共有多少

auto solve() -> void {
   int n = 0, m = 0;
   while (cin >> n >> m) {
      if (n == 0) {
         return;
      }
      vector grid(n, vector<int>(m, 0));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
         }
      }
      int zeroRowCnt = 0, zeroColCnt = 0;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            int x = 0;
            cin >> x;
            grid[i][j] += x;
         }
         if (count(grid[i].begin(), grid[i].end(), 0) == m) {
            zeroRowCnt += 1;
         }
      }
      for (int j = 0; j < m; j++) {
         int cnt = 0;
         for (int i = 0; i < n; i++) {
            if (grid[i][j] == 0) {
               cnt += 1;
            }
            if (cnt == n) {
               zeroColCnt += 1;
            }
         }
      }
      for (auto x : grid) {
         dbg(x);
      }
      dbg(zeroColCnt, zeroRowCnt);
      println(zeroRowCnt + zeroColCnt);
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
