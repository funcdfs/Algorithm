// link: https://atcoder.jp/contests/abc348/tasks/abc348_b B - Farthest Point
// time: 2024/9/20 21:18:25 https://github.com/funcdfs

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

struct point {
   int x, y;
};

void solve() {
   
   int n = 0;
   cin >> n;

   vector<point> p(n);
   for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
   }

   vector<int> ans(n, 0);
   vector<int> ansIdx(n, 0);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int64 distanceX = p[j].x-p[i].x;
         int64 distanceY = p[j].y-p[i].y;
         int64 distance = distanceX*distanceX + distanceY*distanceY;
         if (distance > ans[i]) {
            ans[i] = distance;
            ansIdx[i] = j+1;
         }
      }
   }

   for (int i = 0; i < ssize(ans); i++) {
      cout << ansIdx[i] << '\n';
   }
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
