// link: https://codeforces.com/contest/160/problem/A A. Twins
// time: 2024/9/19 17:51:32 https://github.com/funcdfs

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
#pragma endregion github_funcdfs	// clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve() -> void {
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;

   auto b = a;
   sort(b.begin(), b.end());
   reverse(b.begin(), b.end());

   vector<int64> preSum(n+1, 0);
   for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i-1] + b[i-1];
   }

   int64 sum = accumulate(b.begin(), b.end(), int64_t(0));

   for (int i = 1; i <= n; i++) {
      if (preSum[i] > sum-preSum[i]) {
         println(i);
         return;
      }
   }
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
