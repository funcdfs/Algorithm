// Problem: 最长公共上升子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/274/
// date: 2022-07-22 19:38:02
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for dbg:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    
    return 0;
}

/*

找一下两个序列的 最长公共上升子序列 

4
2 2 1 3
2 1 2 3

2 3

有两个序列，所以试着用二维表示

f[i][j] 

代表 所有在 A{1...i} 中出现 和 B{1...j} 都出现过 
并且以 B[j] 结尾的公共上升子序列的集合

属性: 
	集合中，每一个公共上升子序列的长度的最大值 
	
状态计算: 
	求 f[i][j] 中所有来源的最大值
	左边是 A[i] 不包含在公共子序列中 
		所有在 A{1...i} 中出现 和 B{1...j} 中出现，并且不包含 A[i] 
		所有在 A{1..i-1} 和 B{1...j} 中出现， ......
		也就是 f[i - 1][j] 的值
		
	右边是 包含 A[i] 的公共子序列 
		当 A[i] == B[j] 的时候，右边这个集合才可能存在
		当 A[i] != B[j] 的时候，右边这个集合不可能存在
		
		右边所有的方案，都是以 A{i} 和 B{j} 结尾的
		都是形如 
			xxxxx A[i]
			xxxxx B[j] 
		的匹配方案 
		
		以最后一个不同的元素来进行区间划分:
			也就是按照倒数第二个元素来划分 
			
			倒数第二个数字可能是 b[0]         1  
						可能是 b[1]         f(i - 1, 1) + 1 
						可能是 b[2] 		   f(i - 1, 2) + 1 
						可能是 b[3] 
						可能是 b[j - 1]     f(i - 1, j - 1) + 1 
			因此可以根据倒数第二个元素将 包含 A[i] 的公共子序列分成 j 个子集
			
			那么每一个更小的子集中的最大值求出之后，再求总体的最大值就是右半部分的值了
	
	这就将 f[i][j] 的所有来源搞清楚了
	
	但是现在的时间复杂度是 O(n^3) 的 

时间复杂度未优化版本

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int N = 3010; 

int n; 
int a[N], b[N]; 
int f[N][N]; 

int main() {
    
    cin >> n; 
    
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    for (int i = 1; i <= n; i++) cin >> b[i]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j]; 
            if (a[i] == b[j]) {
                int maxv = 1; 
                for (int k = 1; k < j; k++) {
                    if (b[k] < b[j]) {
                        maxv = max(maxv, f[i - 1][k] + 1); 
                    }
                }
                f[i][j] = max(maxv, f[i][j]);
            }
        }
    }
    
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[n][i]); 
    } 
    
    cout << ans << endl; 
    
    return 0; 
}

时间复杂度优化: 
	
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        f[i][j] = f[i - 1][j]; 
        if (a[i] == b[j]) {
            int maxv = 1; 
            for (int k = 1; k < j; k++) {
                if (b[k] < b[j]) {
                    maxv = max(maxv, f[i - 1][k] + 1); 
                }
            }
            f[i][j] = max(maxv, f[i][j]);
        }
    }
}

由于执行 k 循环的时候 a[i] 和 b[j] 一定相等

所以 b[j] 可以换成 a[i] 

for (int k = 1; k < j; k++) {
	if (b[k] < a[i]) {
		maxv = max(maxv, f[i - 1][k] + 1); 
	}
}

*/