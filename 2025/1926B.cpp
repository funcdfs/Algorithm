// link: https://codeforces.com/contest/1926/problem/B -> B. Vlad and Shapes
// time: 2025/3/10 13:45:41 https://github.com/funcdfs

#pragma region headers_and_definitions // clang-format off
#include <bits/stdc++.h>
using namespace std; /* golang types */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
template <class T> istream &operator>> (istream &cin , vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin , valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); cin.exceptions(ios::badbit | ios::failbit); ios::sync_with_stdio(false);  }} _github_funcdfs; // Global instance
#define endl '\n'
auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#ifdef LOCAL
#include <algo/dbg.h>
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }
#pragma endregion headers_and_definitions       // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve(int _case) -> void {

   int n = 0;
   cin >> n;
   vector<string> g(n);
   for (int i = 0; i < n; i++) {
      cin >> g[i];
   }

   auto check = [&]() -> bool {
      int row1 = -1, col1 = -1;
      int row2 = -1, col2 = -1;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < ssize(g[i]); j++) {
            if (row1 == -1 && col1 == -1 && g[i][j] == '1') {
               row1 = i, col1 = j;
               continue;
            } else if (((row2 == row1 || row2 == -1)) && g[i][j] == '1') {
               row2 = i, col2 = j;
               continue;
            }
         }
      }
      for (int i = 0; i < n; i++) {
         eprintln("{}", g[i]);
      }
      dbg(row1, col1, row2, col2);
      if (row2 == row1+1) {
         if (col1 == col2) {
            return true;
         }
      }
      return false;
   };

   if (check() == true) {
      cout << "SQUARE" << endl;
   } else {
      cout << "TRIANGLE" << endl;
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
