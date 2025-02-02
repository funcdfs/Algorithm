// link: https://codeforces.com/contest/1702/problem/C -> C. Train and Queries
// time: 2025/2/2 19:16:03 https://github.com/funcdfs

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

struct safe_hash {
      static uint64_t splitmix64(uint64_t x) {
         // https://codeforces.net/blog/entry/62393
         x += 0x9e3779b97f4a7c15;
         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
         return x ^ (x >> 31);
      }

      size_t operator()(uint64_t x) const {
         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
         return splitmix64(x + FIXED_RANDOM);
      }
};

auto solve(int _case) -> void {

   // getchar();
   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> u(n, 0);
   cin >> u;
   // if there a road from a to b
   // the trains road is u, u[i-1] --> u[i]
   // if there is a road from a to b, return true, else return false

   unordered_map<int, int, safe_hash> hsl, hsr;
   // map<int, int> hsl, hsr;
   for (int i = 0; i < ssize(u); i++) {
      if (hsl.contains(u[i]) == false) {
         hsl[u[i]] = i;
      }
      hsr[u[i]] = i;
      // hsl[x] store the earliest index of x
      // hsr[x] store the latest index of x
   }
   for (int a=0,b=0, i = 0; i < k; i++) {
      cin >> a >> b;
      if (hsl.contains(a) == true && hsr.contains(b) == true) {
         if (hsl[a] <= hsr[b]) {
            // the start point is earlier than the end point
            println("{}", "YES");
            // cout << "YES" << endl;
         } else {
            println("{}", "NO");
            // cout << "NO" << endl;
         }
      } else {
         println("{}", "NO");
         // cout << "NO" << endl;
      }
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
