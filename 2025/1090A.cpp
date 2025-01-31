// link: https://codeforces.com/contest/1090/problem/A -> A. Company Merging
// time: 2025/1/30 17:59:49 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
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
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs; // Global instance of __init_io to apply I/O settings.
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
#pragma endregion github_funcdfs       // clang-format on


// ----------------------------- /* Start of useful functions */ -----------------------------


void solve() {

   int n = 0;
   cin >> n;
   vector company(n, vector<int>(0, 0));
   for (int i = 0; i < n; i++) {
      int m = 0;
      cin >> m;
      company[i].resize(m);
      cin >> company[i];
   }
   // Two companies can only be merged if their maximum salaries are the same.
   // The leader can increase the salary of the company before merging.
   // The salaries of all employees in the merging company will be increased simultaneously.
   // output the mini count of the increased salary

   vector<int> maxSalary(n, 0);
   unordered_map<int, int> hs;
   for (int i = 0; i < n; i++) {
      maxSalary[i] = *max_element(company[i].begin(), company[i].end());
      hs[maxSalary[i]]++;
   }
   int finalMaxSalary = *max_element(maxSalary.begin(), maxSalary.end());
   dbg(maxSalary, finalMaxSalary);

   int64 ans = 0;
   for (int i = 0; i < n; i++) {
      if (maxSalary[i] != finalMaxSalary) {
         ans += ssize(company[i]) * (finalMaxSalary - maxSalary[i]) ;
      }
   }
   println("{}", ans);

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
