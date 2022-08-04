// URL: https://www.acwing.com/problem/content/5/
// Problem: 多重背包问题 II, Contest: AcWing
// Mem 64 MB, Time 1000 ms
// Date: 2022-08-02 22:40:24

/*
把第 i 种物品打包为 10 组，每一组最多选择一次

1
2
4
8
512

快速幂想法, 预处理这些数字就可以凑出来所有的数字

就是用 10 个新的物品表示原来的物品。然后枚举这 10
种物品选择或者不选择，就可以拼凑出来第 i 中w方案了

然后就是 01 背包问题了

时间复杂度从 nvs 变为了 nvlogs

*/

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 25000;
const int M = 2000;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;

    int cnt = 1;  // 表示所有的新的物品的编号
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        // 读入当前物品的体积价值和个数

        int k = 1;
        while (k <= s) {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }

        if (s > 0) {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt; 
    
    // 然后做一遍 01 背包 
    for (int i = 1; i <= n; i++) {
    	for (int j = m; j >= v[i]; j--) {
    		f[j] = max(f[j], f[j - v[i]] + w[i]); 
    	}
    }
    
    cout << f[m] << endl; 
    
    return 0; 
}