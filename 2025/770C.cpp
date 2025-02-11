// link: https://codeforces.com/contest/770/problem/C -> C. Online Courses In BSU
// time: 2025/2/11 13:25:30 https://github.com/funcdfs

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
   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> mainCourses(k);
   cin >> mainCourses;
   for (auto &x : mainCourses) {
      x -= 1;
   }
   vector<vector<int>> a(n), ra(n);
   vector<int> deg(n);
   for (int i = 0; i < n; i++) {
      int len = 0;
      cin >> len;
      while (len--) {
         int x = 0;
         cin >> x;
         x -= 1;
         ra[i].push_back(x);   // this edge is form x to i, reverse graph store
         deg[i] += 1;          // in degree += 1
         a[x].push_back(i);
      }
   }

   vector<int> need(0, 0);
   vector<bool> visit(n, false);
   function<void(int)> get = [&](int u) {
      if (visit[u] == true) {
         return;
      }
      visit[u] = true;
      need.push_back(u);
      for (auto &v : ra[u]) {
         get(v);
      }
   };
   for (auto &x : mainCourses) {
      get(x);
   }
   // find all needed courses

   vector<int> que(0, 0);
   for (int i = 0; i < n; i++) {
      if (visit[i] == true && deg[i] == 0) {
         que.push_back(i);
      }
   }
   // visis[i] == true and in degree == 0, [ start point ]

   for (int k = 0; k < ssize(que); k++) {
      int u = que[k];
      for (auto &v : a[u]) {   // for all v that u -> v
         deg[v] -= 1;
         if (deg[v] == 0 && visit[v] == true) {
            que.push_back(v);
         }
      }
   }
   // topsort, the que store all the courses that can be taken

   if (ssize(que) != ssize(need)) {
      println("{}", -1);
   } else {
      print("{}\n", ssize(que));
      for (auto &x : que) {
         print("{} ", x + 1);
      }
      print("\n");
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
