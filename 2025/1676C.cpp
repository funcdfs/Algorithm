// link: https://codeforces.com/contest/1676/problem/C -> C. Most Similar Words
// time: 2025/3/11 12:34:43 https://github.com/funcdfs

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

   int n = 0, m = 0;
   cin >> n >> m;

   vector<string> a(n);
   cin >> a;

   int ans = numeric_limits<int32>::max();

   auto process = [&](string s1, string s2) -> int { // usage: [=, &val1, &val2]
      int tot = 0;
      for (int i = 0; i < ssize(s1); i++) {
         if (s1[i] > s2[i]) {
            tot += s1[i]-s2[i];
         } else {
            tot += s2[i]-s1[i];
         }
      }
      dbg(tot);
      return tot;
   };

   for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
         Min(ans, process(a[i], a[j]));
      }
   }

   println("{}", ans);


   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
