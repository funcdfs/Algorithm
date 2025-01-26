// link: https://codeforces.com/contest/370/problem/B -> B. Berland Bingo
// time: 2025/1/23 02:54:02 https://github.com/funcdfs

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
   const int N = 100;
   vector<bitset<N>> a(n);
   // every person's poke use a bitset<N> to store
   for (int i = 0; i < n; i++) {
      int len = 0, x = 0;
      cin >> len;
      while (len--) {
         cin >> x;
         a[i][x-1] = 1;
      }
   }

   for (int i = 0; i < n; i++) {
      bool found = false;
      for (int j = 0; j < n; j++) {
         if (i != j && (a[i]&a[j]) == a[j]) {
            // a[i] is a subarray of a[j]
            found = true;
            break;
         }
      }
      if (found == true) {
         println("NO");
      } else {
         println("YES");
      }
   }
}

void solve_error() {

   int person = 0;
   cin >> person;
   vector<vector<int>> pokes;
   unordered_map<int, int> hs;
   for (int _person = 0; _person < person; _person++) {
      int cnt = 0;
      cin >> cnt;
      vector<int> poke(cnt, 0);
      cin >> poke;
      for (auto& x : poke) {
         hs[x] += 1;
      }
      // if one person is the subcontent for other person, when the total n == 2, this person win
      // if one person is the unique for other person, when the total n == 2, this person win
      pokes.push_back(poke);
   }

   vector<bool> changed(person, false);
   vector<bool> st(person, false);
   for (int i = 0; i < ssize(pokes); i++) {
      for (int j = 0; j < ssize(pokes[i]); j++) {
         if (hs[pokes[i][j]] > 1) {
            pokes[i][j] = -1;
            changed[i] = true;
            // record, this person's poke had changed
         }
      }
   }
   // delete all same part end

   for (int i = 0; i < person; i++) {
      int cnt = count_if(pokes[i].begin(), pokes[i].end(), [=](const auto& xx){
         return xx == -1;
      });
      if (cnt == ssize(pokes[i])) {
         st[i] = true;
      }
   }
   dbg(pokes);
   // if only one st[i] == true; this person is true
   int afterDelete = 0;
   for (int i = 0; i < ssize(st); i++) {
      if (st[i] == true) {
         afterDelete += 1;
      }
   }
   dbg(afterDelete);

   if (afterDelete == 1) {
      // output the single winner, then process the unique player
      for (int i = 0; i < person; i++) {
         // changed[i] == false ---> unique person
         // st[i] == true --> the only clear person
         // change[i] == true &&
         if (changed[i] == false || st[i] == true) {
            println("YES");
         } else {
            println("NO");
         }
      }
   } else {
      // process the unique part
      for (int i = 0; i < person; i++) {
         if (changed[i] == false) {
            println("YES");
         } else {
            println("NO");
         }
      }
   }

   // if exist overlap, and be modified, the two person is both winner
   // 2
   // 2 1 3
   // 2 1 4
   // can not process


   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
