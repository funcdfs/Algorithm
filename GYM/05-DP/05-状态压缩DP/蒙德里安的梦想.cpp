// URL: https://www.acwing.com/problem/content/293/
// NAME: 蒙德里安的梦想, AcWing
// LIMIT: 64 MB, 5000 ms
// DATE: 2022-08-06 13:23:11

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    

    return 0;
}


/*

求，将 N*M 的棋盘分割为若干个 1*2 的长方形，存在多少种分割方案 

核心: 
	先放横着的，再放竖着的， 横着的放完了之后再将竖着的塞进去就可以了
		当横着的小方块选择完毕之后，竖着的小方块只存在一种选择，就是竖着一个一个放进去，所以：
	总方案数量，等于只放横着的小方块的合法的方案数
	
	如何判断当前的方案是否合法：
		判断剩余的位置中，能否填充满竖着的小方块
		每一列的内部所有连续的空着的小方块，需要是偶数个
		
状态表示: 
	f[i,j] 表示已经将前 i-1 列摆好，且从第 i-1 列，伸出到第 i 列的所有方案 
*/