// link: https://codeforces.com/contest/1883/problem/C C. Raspberries
// time: 2024/9/24 18:40:43 https://github.com/funcdfs

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
#define print(...)   std::cout << __VA_ARGS__            /* C++23 std::print()	-> the format string is printed to the standard output */ 
#define println(...) std::cout << __VA_ARGS__ << '\n'    /* C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { std::cout << fixed << setprecision(		15		/* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

#define ssize(x) (int32)((x).size())
template<class T> bool Min(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool Max(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs	// clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve(int _case) -> void {
   dbg(_case);
   
   int n = 0, k = 0; 
   cin >> n >> k;

   vector<int> a(n, 0);
   cin >> a;

   // for zero operation 
   int64 mul = a[0];
   for (int i = 1; i < ssize(a); i++) {
      mul *= (a[i] % k);
      mul %= k;
   }
   if (mul % k == 0) {
      println(0);
      return;
   }

   // k = 2, 3, 5, k == 4;
   if (k == 2 || k == 3 || k == 5) {
      int minCost = numeric_limits<int32>::max();
      for (int i = 0; i < ssize(a); i++) {
         Min(minCost, (k-(a[i]%k)));
      }
      println(minCost);
   } else {
      int oddCnt = count_if(a.begin(), a.end(), [=](const auto& xx){
         return xx % 2 == 1;
      });
      int minCost = numeric_limits<int32>::max();
      if (oddCnt < ssize(a)) {
         Min(minCost, 1);
      } else if (oddCnt == ssize(a)) {
         Min(minCost, 2);
      }
      assert(k==4);
      for (int i = 0; i < ssize(a); i++) {
         Min(minCost, 4-(a[i]%4));
      }
      println(minCost);
   }
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
