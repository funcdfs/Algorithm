// Problem: P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1216
// date: 2022-03-02 17:47:53
// Memory Limit: 125 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int r = 0;
const int N = 1e5 + 10; 
// 定义 n 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r;
    vector<vector<int> g(r, vector<int>(r, 0));
    
    for (int i = 0; i < 10; i++) {
        cin >> a;
    }

    for (int i = 0; i < 10; i++) {
        cout << "hello world" << endl;
    }
    
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int r = 0;
const int N = 1e5 +10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r;
    vector<vector<int>> g(r, vector<int>(r, 0));
}