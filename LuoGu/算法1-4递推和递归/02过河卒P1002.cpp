// Problem: P1002 [NOIP2002 普及组] 过河卒
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1002
// date: 2022-02-10 20:58:57
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 小兵只可以向右侧或者向下进行走路
    // 中间有一个马，马可以抵达的坐标卒不可以走
    // 给定小兵的起始坐标和小兵的目的坐标
    // 输出所有可能的路径总数
    
    int finalx = 0;
    int finaly = 0;
    int horsex = 0;
    int horsey = 0;
    cin >> finalx >> finaly >> horsex >> horsey;
    
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    vector<vector<LL>> f(finalx + 1, vector<LL>(finaly + 1, 0L));
    
    f[horsex][horsey] = -1L;
    for (int i = 0; i < 8; i++) {
    	int a = horsex + dx[i];
    	int b = horsey + dy[i];
    	if (a >= 0 && b >= 0 && a <= finalx && b <= finaly) {
    		f[a][b] = -1;
    	}
    }
    
    for (int i = 0; i <= finalx; i++) {
    	if (f[i][0] == 0) {
    		f[i][0] = 1;
    	} else {
    		break; // 遇到一个马之后，直线走的话，之后的路线都为不可达路线！
    	}
    }
    // for (int i = 0; i <= finaly; i++) f[0][i] = 1;
    // 所以不能这样粗暴的赋值，及时止损
    for (int i = 0; i <= finaly; i++) {
    	if (f[0][i] != -1) f[0][i] = 1;
    	else break;
    }
/* 
  1  1  1  1  1  1  1
  1 -1  1  2  3  4  5
  1  1 -1  2  5  9 14
 -1  1  1  3  8 17 31
  0  1 -1  3 11 28 59
  0 -1  0  3 14 42101
  0  0  0  3 17 59160
160
*/

    
    for (int i = 1; i <= finalx; i++) {
    	for (int j = 1; j <= finaly; j++) {
    		if (f[i][j] == -1L) continue;
    		LL a = f[i][j - 1];
    		LL b = f[i - 1][j];
    		f[i][j] = a + b;
    		if (f[i][j - 1] == -1) f[i][j] += 1;
    		if (f[i - 1][j] == -1) f[i][j] += 1;
    	}
    }
    // for (auto x : f) {
    	// for (auto y : x) {
    		// cout.setf(ios::right);
    		// cout.width(3);
    		// cout << y;
    	// }
    	// cout << endl;
    // }
  // 1  1  1  1  1  1  1
  // 1  2 -1  1 -1  1  2
  // 1 -1  0  1  1 -1  2
  // 1  1  1 -1  1  1  3
  // 1 -1  1  1  2 -1  3
  // 1  1 -1  1 -1  0  3
  // 1  2  2  3  3  3  6
// 6

    cout << f[finalx][finaly] << endl;
    // 使用LL存储
    return 0;
}






































