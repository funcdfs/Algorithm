// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // 

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    
    return 0;
}

    // 基于连通性的 DP 
    // 棋盘式的 DP 
    // 集合 
    
    // 递归实现指数型枚举 
    
/*
蒙德里安的梦想
Hamilton路径 

骑士 
n*n 的棋盘
放置 k 个国王， 使得国王不会相互攻击 

相比蒙德里安的梦想变为了其他类型的图形 

每一行都之和上一行相关 

状态表示 
f[i, j, s] 
所有只摆放在前 i 行， 已经摆放了 j 个国王， 并且第 i 行摆放那个的状态是 s 的集合 

s 是一个 n 位的二进制数字  递归实现指数型枚举  的方式 



f[i][j] 表示前 i 行已经放置完毕，并且当前行放置了 j 个棋子，并且最后一行状态是 s 的方案数量 

考虑 f[i][j][s] 的来源 



*/
