// link: https://codeforces.com/contest/1840/problem/C C. Ski Resort
// time: 2024/9/23 00:55:20 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>			  &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>			&a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>			&a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>	&a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'	 /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)   std::cout << __VA_ARGS__ 			  /* C++23 std::print()	-> the format string is printed to the standard output */ 
#define println(...) std::cout << __VA_ARGS__ << '\n' /* C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(		15		/* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)		;
#define eprint(...)	;
#define eprintln(...) ;
#endif

#define ssize(x) (int32)((x).size())
template<class T> bool Min(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool Max(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

// Define global variables:
const int32 MAX_N = 1e7 + 10;
const int32 INF_INT_32 = 0x3f3f3f3f;
const int64 INF_INT_64 = 0x3f3f3f3f3f3f3f3fll;
const float64 EPS = 1e-12;
const float64 PI = 3.141592653589793;

int64 sum[MAX_N];

// Initialize global variables function, all initialization code for global variables:
int initGlobalVar = []() {
   for (int i = 1; i <= MAX_N; i++) {
      sum[i] = sum[i - 1] + i;
   }

   return 0;
}();

auto solve(int _case) -> void {
   dbg(_case);

   int n = 0, k = 0, q = 0;
   cin >> n >> k >> q;

   vector<int> a(n, 0);
   cin >> a;

   // sequence length >= k
   // sequence maxmium number <= q

   int64 cnt = 0;
   for (int i = 0, j = 0; i < n; i = j) {
      for (j = i + 1; j < n && a[j] <= q && a[j - 1] <= q; j++) { }
      if (a[i] <= q && j - i >= k) {
         cnt += sum[j - i - k + 1];
         // \sum_{i=1}^{len-k+1} i
         // len == j-i
         // choose len     cnt == 1
         // choose len-1   cnt == 2
         // choose len-2   cnt == 3
         // choose len-i   cnt == len-i+1
         // min(len-i)==k  cnt == len-k+1;
         // so, when len == j-i
         // all the sum ==
         //     \sum_{i=1}^{len-k+1}
         // this value can be cal global, O(1) fetch
      }
      // cnt += 1;
   }
   println(cnt);

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
