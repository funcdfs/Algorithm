// link: https://codeforces.com/contest/342/problem/A -> A. Xenia and Divisors
// time: 2025/1/31 14:22:58 https://github.com/funcdfs

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
#pragma endregion headers_and_definitions   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

void solve() {
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;

   // if required partition exists, output n/3 groups [a, b, c]
   //    b%a == 0, c%b == 0, c%a == 0
   // if there is no solution, print -1

   // 124.
   // 136.
   // 126.
   unordered_map<int, int> hs;
   for (auto &x : a) {
      hs[x] += 1;
      if (x == 5 || x == 7) {
         // the final group dont have 5 or 7
         cout << -1 << endl;
         return;
      }
   }
   if (ssize(hs) < 3 || (hs[4]+hs[3] > ssize(a)-hs[4]-hs[3])) {
      // group 1 spefic number and group 2 spefic number is more than the reset
      cout << -1 << endl;
      return;
   }
   dbg(hs,a);

   hs[1] -= hs[4];   // make group 1
   hs[2] -= hs[4];   // make group 1
   if (hs[1] < 0 || hs[2] < 0) {
      // can not make group 1
      cout << -1 << endl;
      return;
   }

   hs[6] -= hs[3];   // make group 2
   hs[1] -= hs[3];   // make group 2
   if (hs[6] < 0 || hs[1] < 0) {
      // can not make group 2
      cout << -1 << endl;
      return;
   }

   if (hs[1] != hs[2] || hs[1] != hs[6] || hs[2] != hs[6]) {
      // the remaining number can not make group 3
      cout << -1 << endl;
      return;
   }
   eprintln("after");
   dbg(hs, a);

   for (int i = 0; i < hs[4]; i++) {
      cout << "1 2 4" << endl;
   }
   for (int i = 0; i < hs[3]; i++) {
      cout << "1 3 6" << endl;
   }
   for (int i = 0; i < hs[1]; i++) {
      cout << "1 2 6" << endl;
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
