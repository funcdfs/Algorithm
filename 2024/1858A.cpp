// link: https://codeforces.com/contest/1858/problem/A A. Buttons
// time: 2024/9/17 12:20:02 https://github.com/funcdfs

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
#define print(...)   std::cout << /*format*/(__VA_ARGS__) /* mac os: C++23 std::print()   -> the format string is printed to the standard output */ 
#define println(...) std::cout << __VA_ARGS__ << '\n' /* mac os: C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve(int _case) -> void {
   dbg(_case);

   int a, b, c;
   cin >> a >> b >> c;
   /*

1 2 2
a, b, a[c], b, a[c], b[lost]
a[c], b[c], a, b, a[lost]


   */
   if (c & 1) {
      b -= 1;
   } else {
      // do nothing;
   }

   bool fir = true;
   if (a > b) {
      fir = true;
   } else if (a <= b) {
      fir = false;
   }
   goto Final;
/*
   bool fir = true;
   // consume one person to zero
   if (a > b) {
      a -= b, b = 0;
   } else if (a < b) {
      b -= a, a = 0;
   } else if (a == b) {
      a = 0, b = 0;
   }

   assert(a==0 || b==0);
   dbg(a, b, c);
   // consume one (a, b) || c to zero
   if (a == 0 && b == 0) {
      if (c & 1) {
         fir = true;
      } else {
         fir = false;
      }
      goto Final;
   } else if (a == 0) {
      if (c >= b) {
         c -= b;
         b = 0;
         if (c & 1) {
            fir = true;
         } else {
            fir = false;
         }
      } else if (c < b) {
         fir = false;
      }
   } else if (b == 0) {
      if (c >= a) {
         c -= a;
         a = 0;
         // b use c first
         if (c % 2 == 1) {
            fir = false;
         } else {
            fir = true;
         }
      } else if (c < a) {
         // b+c < a;
         fir = true;
      }
   }
   dbg("final");
   dbg(a, b, c);
*/
Final:
   if (fir == true) {
      println("First");
   } else {
      println("Second");
   }
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
