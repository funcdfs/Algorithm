# 万物皆虚

</br>


<details>
<summary> config1: compile command </summary>
</br>

```sh
-std=c++2b -D LOCAL -Wno-string-compare -Wno-deprecated-array-compare -fno-omit-frame-pointer -fno-inline -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -fsanitize=undefined -fsanitize=address -fstack-protector -Wall -Wextra
```
</details>



<details>
<summary> config2: <code> algo/dbg.h </code> For Debugging Purposes </summary>
</br>

`dbg.h` file: [gist.github.com/funcdfs/algo/dbg.h](https://gist.github.com/funcdfs/093ea21e3e3d033298191a5f4c635069)

</details>


</br>

---

</br>


<details>
<summary> template </summary>
</br>

```

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
#define print(...)   std::cout << format(__VA_ARGS__)           /* C++23 std::print()   -> the format string is printed to the standard output */
#define println(...) std::cout << format("{0}\n", __VA_ARGS__); /* C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { std::cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs;

#ifdef LOCAL /* For local debugging purposes */
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

auto solve() -> void; /* main --> */ int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve() -> void {



   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------




```


</details>



</br>
