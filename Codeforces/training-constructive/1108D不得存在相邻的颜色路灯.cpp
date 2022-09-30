// LINK: https://codeforces.com/contest/1108/problem/D
// NAME: D. Diverse Garland, Codeforces - Codeforces Round #535 (Div. 3)
// DATE: 2022.09.15 21:50:08, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

char diff(char a, char b) {
    unordered_map<char, int> hs;
    hs['R']++;
    hs['G']++;
    hs['B']++;
    hs[a]--, hs[b]--;
    for (auto& [k, v] : hs) {
        if (v > 0) {
            return k;
        }
    }
    return 'x';
}
char diff(char a) {
    unordered_map<char, int> hs;
    hs['R']++;
    hs['G']++;
    hs['B']++;
    hs[a]--;
    for (auto& [k, v] : hs) {
        if (v > 0) {
            return k;
        }
    }
    return 'x';
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    string s = string(n, ' ');
    cin >> s;

    string changed = "";
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        string t = s.substr(i, j - i);
        char backEle = s[j];
        /* s[l] to s[r] is the same color lamps*/

        dbg("origin t: ", t);
        if (t.size() >= 2) {
            int idx = 1;
            while (idx <= t.size()) {
                t[idx] = diff(t[idx - 1]);
                idx += 2;
            }
            char backEle = j == n ? t.rbegin()[1] : s[j]; 
            if (t.back() == backEle) {
                t.back() = diff(t.rbegin()[1], backEle); 
            }
            dbg(t, backEle);
        }
        i = j - 1;
        changed += t;
    }

    int changedCnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != changed[i]) {
            changedCnt++;
        }
    }

    cout << changedCnt << '\n';
    cout << changed << '\n';

    return 0;
}

/*

1108D不得存在相邻的颜色路灯


策略:
    从前往后扫描，遇到和前面一个不一样的字符就进行修改
    注意变的时候，如果当前字符是当前相同字符段的最后一个字符
    那么变到不是前一个和不是后一个的位置

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220915224309.png)
    
*/