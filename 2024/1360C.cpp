// link: https://codeforces.com/contest/1360/problem/C C. Similar Pairs
// time: 2024/9/30 00:42:03 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h>
/* ----------------------------- using golang types ----------------------------- */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long; using namespace std;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
/* ----------------------------- Macro Functions ----------------------------- */
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }  // For diff types: If b is less than a, update a and return true.
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }  // For diff types: If b is greater than a, update a and return true.
/* ----------------------------- Debugging tools ----------------------------- */
#ifdef LOCAL             // for local builds; disabled in online builds
#include "algo/dbg.h"    // Include debugging utilities when running locally.
#else
#define dbg(...)      ;  // Disable debug output in non-local builds.
#define eprint(...)   ;  // Disable error printing in non-local builds.
#define eprintln(...) ;  // Disable error printing with newline in non-local builds.
#endif
/* ----------------------------- Define efficient I/O macros ----------------------------- */
#define endl '\n'     // Use '\n' instead of std::endl to avoid flushing the output buffer, improving performance.
#define print(...)    std::cout << format(__VA_ARGS__)           /* C++23 std::print()   -> the format string is printed to the standard output */
#define println(...)  std::cout << format("{0}\n", __VA_ARGS__); /* C++23 std::println() -> to print a single value and append a newline */
template <class T> istream &operator>> (istream &cin, vector<T>            &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   /* Set the floating-point precision */); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs; // Global instance of __init_io to apply I/O settings.
auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;

   auto check = [&]() -> bool {
      vector<int> even(0, 0), odd(0, 0);
      for (int i = 0; i < n; i++) {
         if (a[i] % 2 == 0) {
            even.push_back(a[i]);
         } else {
            odd.push_back(a[i]);
         }
      }
      int cnt = (ssize(even)%2==0)+(ssize(odd)%2==0);
      if (cnt == 2) {
         return true;
      } else if (cnt == 1) {
         return false;
      } else {
         // both of even and odd size is odd number;
         sort(a.begin(), a.end());
         for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]+1) {
               return true;
            }
         }
         return false;
      }
      return false;
   };

/* one even, one odd || abs(a[i]-a[i-1]) == 1
   auto check = [&]() -> bool {
      if (n % 2 == 1) {
         return false;
      }
      int evenCnt = count_if(a.begin(), a.end(), [=](const auto& xx){
         return xx % 2 == 0;
      });
      int oddCnt = ssize(a) - evenCnt;
      if (evenCnt == oddCnt) {
         return true;
      } else {
         if (evenCnt > oddCnt) {
            int diff = evenCnt - oddCnt;
            if (diff % 2 == 1) {
               return false;
            }
            vector<int> x(0, 0);
            for (int i = 0; i < n; i++) {
               if (a[i] % 2 == 0) {
                  x.push_back(a[i]);
               }
            }
            sort(x.begin(), x.end());
            int success = 0;
            for (int i = 0; i < ssize(x)-1; i++) {
               if (x[i] == x[i+1]-1) {
                  success += 1;
                  i += 1;
               } else {
               }
            }
            if (success >= diff) {
               return true;
            } else {
               return false;
            }
         } else if (oddCnt > evenCnt) {
            vector<int> x(0, 0);
            int diff = oddCnt - evenCnt;
            for (int i = 0; i < n; i++) {
               if (a[i] % 2 == 1) {
                  x.push_back(a[i]);
               }
            }
            sort(x.begin(), x.end());
            int success = 0;
            for (int i = 0; i < ssize(x)-1; i++) {
               if (x[i] == x[i+1]-1) {
                  success += 1;
               }
            }
            if (success >= diff) {
               return true;
            } else {
               return false;
            }
         }
      }
   };
*/
   if (check() == true) {
      println("YES");
   } else {
      println("NO");
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
