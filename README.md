没有什么是暴搜不可以解决的。

gcc version 14.1.0 (MinGW-W64)

```c++
-std=gnu++2a -D LOCAL -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align
```

dbg.h

```c++
using namespace std;

#define dbg(...) \
    pr("(", ">>> ", __LINE__, ")[", #__VA_ARGS__, "]: ["), pc(__VA_ARGS__)
// #define dbg(...) pr("(", __func__, " ", __LINE__, ")[", #__VA_ARGS__, "]:
// ["), pc(__VA_ARGS__)

template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
auto re = [](auto&&... args) { (cin >> ... >> args); };

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

#define Vout(Con)                                 \
    template <class T>                            \
    ostream& operator<<(ostream& os, Con<T>& v) { \
        bool fst = 1;                             \
        os << "{";                                \
        for (auto& x : v) {                       \
            if (!fst) os << ", ";                 \
            os << x;                              \
            fst = 0;                              \
        }                                         \
        os << "}";                                \
        return os;                                \
    }
#define Vout2(Con)                                     \
    template <class T1, class T2>                      \
    ostream& operator<<(ostream& os, Con<T1, T2>& v) { \
        bool fst = 1;                                  \
        os << "{";                                     \
        for (auto& [x, y] : v) {                       \
            if (!fst) os << ", ";                      \
            os << x << ": " << y;                      \
            fst = 0;                                   \
        }                                              \
        os << "}";                                     \
        return os;                                     \
    }
Vout(vector) Vout(set) Vout(multiset) Vout2(map)

#define Out(f, delim, lst)                    \
    auto f = [](auto&& arg, auto&&... args) { \
        cerr << arg;                          \
        ((cerr << delim << args), ...);       \
        cerr << lst;                          \
    };
    Out(pr, "", "") Out(pw, ' ', ' ') Out(ps, ' ', '\n';)
        Out(pc, ", ", "]" << '\n';)

            auto ptrace = [](const char* name, auto&& A, auto&&... rest) {
                const char* open = strchr(name, '[');
                cerr.write(name, open - name);
                ((cerr << '[' << rest << ']'), ...);
                cerr << " = " << A << '\n';
                ;
            };
/*

author: https://github.com/funcdfs

Head File For Local Debugging Purposes

usage:

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

dbg({any});
eg: int a = 10; dbg(a); dbg("HI");
*/
```