// link: https://codeforces.com/contest/1692/problem/C -> C. Where's the Bishop?
// time: 2025/3/11 15:51:25 https://github.com/funcdfs

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
void solve(); int32 main() { solve(); return 0; }
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


void solve() {

   int tt = 0;
   cin >> tt;
   vector<string> g(8, string(8, '.'));
   auto findPosition = [&]() -> pair<int, int> { // usage: [=, &val1, &val2]
      int x = 0, y = 0;
      for (int i = 0; i < 8; i++) {
         for (int j = 0; j < 8; j++) {
            if (g[i][j] == '#') {
               int x1 = i-1, y1 = j-1;
               int x2 = i-1, y2 = j+1;
               int x3 = i+1, y3 = j-1;
               int x4 = i+1, y4 = j+1;
               if (
                  (x1 >= 0 && y1 >= 0 && x1 < 8 && y1 < 8) &&
                  (x2 >= 0 && y2 >= 0 && x2 < 8 && y2 < 8) &&
                  (x3 >= 0 && y3 >= 0 && x3 < 8 && y3 < 8) &&
                  (x4 >= 0 && y4 >= 0 && x4 < 8 && y4 < 8)
               ) {
                  if (
                     (g[x1][y1] == '#') &&
                     (g[x2][y2] == '#') &&
                     (g[x3][y3] == '#') &&
                     (g[x4][y4] == '#')
                  ) {
                     x = i+1;
                     y = j+1;
                     return make_pair(x, y);
                  }
               }
            }
         }
      }
      return make_pair(x, y);
   };
   while (tt--) {
      for (int i = 0; i < 8; i++) {
         cin >> g[i];
      }
      auto [x, y] = findPosition();
      cout << x << ' ' << y << endl;
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
