// link: https://codeforces.com/contest/920/problem/B -> B. Tea Queue
// time: 2025/1/28 13:10:30 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h>
using namespace std; /* golang types */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
template <class T> istream &operator>> (istream &cin, vector<T>            &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs; // Global instance of __init_io to apply I/O settings.
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
#pragma endregion github_funcdfs       // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve(int _case) -> void {

   int n = 0;
   cin >> n;
   vector<int> l(n,0), r(n,0);
   for(int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
   }
   // n represents the number of people in the queue
   // l[i] represents the time when the i-th person will start drinking tea
   // r[i] represents the time when the i-th person will finish drinking tea

   int current_time = 0;
   vector<int> ans(0, 0);
   for (int i = 0; i < n; i++) {
      if (current_time <= l[i]) {
         ans.push_back(l[i]); // one person start drinking tea
         current_time = l[i]+1; // the end time of this person update
      } else if (current_time <= r[i]) {
         ans.push_back(current_time);
         current_time++;
      } else if (current_time > r[i]) {
         ans.push_back(0);
      }
   }
   cout << ans << endl;

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
