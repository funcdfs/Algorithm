// link: https://www.acwing.com/problem/content/description/1099/ 池塘计数
// time: 2024/7/8 16:15:00 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'    /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)   cout << format(__VA_ARGS__)           /* the format string is printed to the standard output */ 
#define println(...) cout << format("{0}\n", __VA_ARGS__); /* to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve() -> void {
   
   int n = 0, m = 0;
   cin >> n >> m;
   vector<string> g(n);
   cin >> g;

   vector st(n, vector<bool>(m, false)); 
   int ans = 0;
   array<int, 8> dx = {0, 1, 1, 1, 0, -1, -1, -1};
   array<int, 8> dy = {1, 1, 0, -1, -1, -1, 0, 1};
   
   auto bfs = [&](int x, int y) -> void {
      queue<pair<int, int>> que;
      que.push({x, y}); 
      st[x][y] = true; 
      while (que.size()) {
         auto [tx, ty] = que.front(); 
         que.pop(); 
         for (int d = 0; d < int(dx.size()); d++) {
            int nx = dx[d] + tx; 
            int ny = dy[d] + ty; 
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && st[nx][ny] == false && g[nx][ny] == 'W') {
               que.push({nx, ny}); 
               st[nx][ny] = true; 
            }
         }
      }
   };

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (st[i][j] == false && g[i][j] == 'W') {
            bfs(i, j);
            ans += 1; 
         }
      }
   }

   cout << ans << endl; 
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
