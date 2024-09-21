// link: https://codeforces.com/contest/349/problem/A A. Cinema Line
// time: 2024/9/21 11:49:47 https://github.com/funcdfs

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
   bool ok = true;

   // int64 now = 0;
   // for (int i = 0; i < int(a.size()); i++) {
   //    dbg(a[i], now);
   //    if (a[i] == 25) {
   //       now += a[i];
   //    } else if (a[i] != 25) {
   //       int reward = a[i] - 25;
   //       if (now < reward) {
   //          println("NO");
   //          return;
   //       } else {
   //          now -= reward;
   //          if (now < 0) {
   //             println("NO");
   //             return;
   //          }
   //          now += 25;
   //       }
   //    }
   // }
   // println("YES");


   // not the price, the money can not split 
   unordered_map<int, int> hs;
   for (int i = 0; i < int(a.size()); i++) {
      if (a[i] == 25) {
         hs[a[i]] += 1;
      } else {
         if (a[i] == 50) {
            if (hs[25] <= 0) {
               println("NO");
               return;
            }
            hs[25] -= 1;
            hs[50] += 1;
         } else if (a[i] == 75) {
            if (hs[50] <= 0) {
               println("NO");
               return;
            }
            hs[50] -= 1;
            hs[50] += 1;
            hs[25] += 1;
         } else if (a[i] == 100) {
            int ok = 0;
            if (hs[50] >= 1 && hs[25] >= 1) {
               ok = 1;
               hs[50] -= 1;
               hs[25] -= 1;
               hs[100] += 1;
            } else if (hs[25] >= 3) {
               ok = 1;
               hs[25] -= 3;
               hs[100] += 1;
            }
            if (ok == 0) {
               println("NO");
               return;
            }
         }
      }
   }

   println("YES");
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
