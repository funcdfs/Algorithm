// link: https://www.acwing.com/problem/content/101/ -> 激光炸弹
// time: 2025/3/8 20:14:05 https://github.com/funcdfs

#pragma region headers_and_definitions // clang-format off
#include <bits/stdc++.h>
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double;
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin , valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'    /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); cin.exceptions(ios::badbit | ios::failbit); ios::sync_with_stdio(false);  }} _github_funcdfs; // Global instance

#define ssize(x) (int32)((x).size()) /* support C++20: std::ssize() feature*/
template<class T> bool Min(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool Max(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#pragma endregion headers_and_definitions   // clang-format on
#ifdef LOCAL
#include <algo/dbg.h>
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif
// ----------------------------- /* Start of useful functions */ -----------------------------

const int N = 5010;
int s[N][N];

int main() {
   int n = 0, R = 0;
   cin >> n >> R;
   R = min(R, 5001);

   for (int i = 0; i < n; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      x += 1, y += 1;
      s[x][y] += w;
   }

   for (int i = 1; i <= 5001; i++) {
      for (int j = 1; j <= 5001; j++) {
         s[i][j] += s[i-1][j]
                  + s[i][j-1]
                  - s[i-1][j-1];
      }
   }

   int ans = 0;
   // each start node, the edge [ len == R-1 ]
   for (int i = R; i <= 5001; i++) {
      for (int j = R; j <= 5001; j++) {
         ans = max(ans, s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
      }
   }

   cout << ans << endl;

   return 0;
}