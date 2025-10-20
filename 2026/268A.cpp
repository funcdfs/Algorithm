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
   vector<pair<int, int>> a;
   for (int i = 0; i < n; i++) {
      int x = 0, y = 0;
      cin >> x >> y;
      a.emplace_back(x, y);
   }
   int ans = 0;
   unordered_map<int, int> zhuCnt, keCnt;
   for (int i = 0; i < n; i++) {
      zhuCnt[a[i].first]++;
      keCnt[a[i].second]++;
   }
   dbg(zhuCnt);
   unordered_map<int, int> backUpZhu = zhuCnt, backUpKe = keCnt;
   for (int i = 0; i < n; i++) {
      int x = 0;
      backUpKe = keCnt;
      backUpZhu = zhuCnt;
      if (a[i].first == a[i].second) {
         if (keCnt.count(a[i].first) > 1) {
            ans += keCnt[a[i].first] - 1;
            keCnt[a[i].first] -= 1;
            zhuCnt[a[i].first] -= 1;
         }
         if (zhuCnt.count(a[i].second) > 1) {
            ans += zhuCnt[a[i].second] - 1;
            zhuCnt[a[i].second] -= 1;
            keCnt[a[i].second] -= 1;
         }
      } else {
         if (keCnt.contains(a[i].first)) {
            x += keCnt[a[i].first];
            keCnt[a[i].first]--;
            zhuCnt[a[i].first]--;
         }
         if (zhuCnt.contains(a[i].second)) {
            x += zhuCnt[a[i].second];
            zhuCnt[a[i].second]--;
            keCnt[a[i].second]--;
         }
      }
      ans += x;
      zhuCnt = backUpZhu;
      keCnt = backUpKe;
   }
   cout << ans / 2 << endl;

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
