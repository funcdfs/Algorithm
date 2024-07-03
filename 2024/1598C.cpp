// link: https://codeforces.com/contest/1598/problem/C C. Delete Two Elements
// time: 2024/7/1 17:39:32 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
template <class T> istream &operator>> (istream &cin,  vector<T>                 &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> istream &operator>> (istream &cin,  valarray<T>               &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>                 &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, const valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, const vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, const vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl           '\n'
#define print(...)     cout << format(__VA_ARGS__)
#define println(...)   cout << format("{0}\n", __VA_ARGS__)
struct _INIT_IO_END { _INIT_IO_END() { cout << fixed <<      setprecision(   15   );  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 
#ifdef  LOCAL //  dbg
#include "algo/dbg.h"
#else
#define dbg(...)    ;
#define eprint(...) ;
#endif
auto solve(int _case) -> void; int32 main() {       int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;

   unordered_map<int, int> hs;
   int64 sum = accumulate(a.begin(), a.end(), int64_t(0));
   if ((2 * sum) % n != 0) {
      println(0);
      return;
   }
   int64 need = (2 * sum) / n;
   int64 ans = 0;
   for (int i = 0; i < n; i++) {
      int a1 = a[i];
      int a2 = int32(need - a1);
      if (hs.contains(a2)) {
         ans += hs[a2];
      }
      hs[a[i]] += 1;
   }

   println(ans);

   return;
}

// -------------------------------------------------------------------
