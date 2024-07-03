// link: https://www.acwing.com/problem/content/description/843/ 字符串哈希
// time: 2024/7/3 14:58:32 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
template <class T> istream &operator>> (istream &cin,  vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl           '\n'
#define print(...)     cout << format(__VA_ARGS__)
#define println(...)   cout << format("{0}\n", __VA_ARGS__)
struct _INIT_IO_END { _INIT_IO_END() { cout << fixed << setprecision(   15   );  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 
#ifdef  LOCAL //  dbg
#include "algo/dbg.h"
#else
#define dbg(...)    ;
#define eprint(...) ;
#endif
auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

#pragma region StringHashDefineCode // !! don't forget		  initStringHash();

const int mod1 = 1e9 + 7, base1 = 27;
const int mod2 = 1e9 + 9, base2 = 31;	//	31	131	 13131
const int maxn = 1e6 + 10;
int64 val1[maxn], val2[maxn];

void initStringHash() {
   val1[0] = val2[0] = 1;
   for (int i = 1; i < maxn; i++) {
      val1[i] = val1[i - 1] * base1 % mod1;
      val2[i] = val2[i - 1] * base2 % mod2;
   }
}

struct StringHash {
      string s;
      vector<int64> hash1, hash2;

      StringHash(string _s) : s(_s), hash1 {0}, hash2 {0} {
         for (auto i : s) {
            hash1.push_back((hash1.back() * base1 % mod1 + i) % mod1);
            hash2.push_back((hash2.back() * base2 % mod2 + i) % mod2);
         }
      }

      void add(string news) {
         s += news;
         for (auto i : news) {
            hash1.push_back((hash1.back() * base1 % mod1 + i) % mod1);
            hash2.push_back((hash2.back() * base2 % mod2 + i) % mod2);
         }
      }

      pair<int64, int64> get() {
         return {hash1.back(), hash2.back()};
      }

      pair<int64, int64> substrRange(int l, int r) {
         int64 a = ((hash1[r + 1] - hash1[l] * val1[r - l + 1] % mod1) % mod1 + mod1) % mod1;
         int64 b = ((hash2[r + 1] - hash2[l] * val2[r - l + 1] % mod2) % mod2 + mod2) % mod2;
         return {a, b};
      }

      pair<int64, int64> substr(int st, int len) {
         int l = st, r = st + len - 1;
         int64 a = ((hash1[r + 1] - hash1[l] * val1[r - l + 1] % mod1) % mod1 + mod1) % mod1;
         int64 b = ((hash2[r + 1] - hash2[l] * val2[r - l + 1] % mod2) % mod2 + mod2) % mod2;
         return {a, b};
      }
};

#pragma endregion StringHashDefineCode	// !! don't forget		  initStringHash();

// -------------------------------------------------------------------
auto solve() -> void {
   
   initStringHash();
   int n = 0, m = 0;
   cin >> n >> m;
   string s;
   cin >> s;
   StringHash hs(s);

   while(m--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      a--, b--, c--, d--;
      if (hs.substrRange(a, b) == hs.substrRange(c, d)) {
         cout << "Yes\n";
      } else {
         cout << "No\n";
      }
   }
   
   return;
}

// -------------------------------------------------------------------
