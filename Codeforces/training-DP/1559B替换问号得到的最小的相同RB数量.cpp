// URL: https://codeforces.com/contest/1559/problem/B
// NAME: B. Mocha and Red and Blue, Codeforces - Codeforces Round #738 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-12 18:30:24

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

map<char, char> m;

string paintSquare(string& s) {
    // 在问号的位置填充 B 或者 R 求最终的 【相邻对】 数量最小的填充方案
    int i = 0; 
    while (i < s.size()) {
        if (s[i] != '?') {
            char l = m[s[i]]; 
            int j = i - 1; 
            while (j >= 0 && s[j] == '?') {
                s[j] = l; 
                l = m[l]; 
                j--; 
            }
        }
        i++;                     
    } // 将除了最后一段的位置都填满 

    i--; 
    char l; 
    while (i >= 0 && s[i] == '?') {
        i--; 
    } 
    if (i < 0) {
        i = 0; 
        l = 'B'; 
    } else {
        l = m[s[i]]; 
        i++; 
    }
    while (i < s.size()) {
        s[i] = l; 
        l = m[l]; 
        i++; 
    } // 然后将最后一段都填满
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    m['R'] = 'B';
    m['B'] = 'R';

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n; 
        string s = "";
        cin >> s;
        cout << paintSquare(s) << endl;
    }

    return 0;
}

/*

1559B替换问号得到的最小的相同RB数量

每一个填充字段的中间肯定越少越好，所以可以使得每一个填充到
？的内容都是互不相同的 所以最终的不完美的数量之和两边的颜色相关

如果所有的字符都是 ？只需要把奇数位置换为 R 偶数位置换为 B 即可

对于分段的场景，可以找到的哥不是 ？ 的位置，记为 i
在 i 之前的字符都可以从 i - 1
的位置往左扫描，把相应的字符替换为和右边相邻字符不同的字符



*/