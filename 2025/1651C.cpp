// link: https://codeforces.com/contest/1651/problem/C -> C. Fault-tolerant Network
// time: 2025/1/31 12:52:17 https://github.com/funcdfs

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
   vector<int> a(n, 0);
   vector<int> b(n, 0);
   cin >> a >> b;
   // connect the network, make the network fault-tolerant
   // output the minimun number of the connect cost
   // add one edge, the cost is |a[i] - b[j]|

   // (1, 1) (2, 1) + (1, n) (2, n)
   // (1, 1) (2, n) + (1, n) (2, 1)
   // case1: two edge
   int64 ans = numeric_limits<int64>::max();
   Min(ans, abs(a[0]-b[0])+abs(a[n-1]-b[n-1]));
   Min(ans, abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));

   // case2: three edge
   int64 a1 = numeric_limits<int64>::max();
   int64 an = a1, b1 = a1, bn = a1;
   for (int i = 0; i < n; i++) {
      Min(a1, abs(b[i]-a[0]));
      Min(an, abs(b[i]-a[n-1]));
      Min(b1, abs(a[i]-b[0]));
      Min(bn, abs(a[i]-b[n-1]));
   } // Precompute the minimum cost for connecting a single edge from a[0] to any b[i], a[n-1] to any b[i], b[0] to any a[i], and b[n-1] to any a[i]
   ans = min({
      ans,
      abs(a[0]-b[0])+an+bn,     // three edge case
      abs(a[n-1]-b[n-1])+a1+b1, // three edge case
      abs(a[0]-b[n-1])+an+b1,   // three edge case
      abs(a[n-1]-b[0])+a1+bn,   // three edge case
   });

   // case3: four edge
   Min(ans, a1+an+b1+bn);

   println("{}", ans);

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------