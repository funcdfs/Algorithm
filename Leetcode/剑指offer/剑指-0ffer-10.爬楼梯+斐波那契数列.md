[题目链接](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)  
[题解链接](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/jz101-fengwei2002-dp-by-kycu-qjgn/)

https://github.com/fengwei2002/algorithm

### 剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

**答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。**


### 思路

祖传 DP 入门题目，多了一个条件，不要看漏题目

### C++

``` cpp
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;

        int f1 = 0;
        int f2 = 1;
        int f3 = 1;
        for (int i = 3; i <= n; i++) {
            f1 = f2, f2 = f3;
            f3 = (f1 + f2) % int(1e9 + 7);
        }
        return f3;
    }
};
```

### GO

``` go
func fib(n int) int {
    const mod int = 1e9 + 7
    if n == 0 {
        return 0
    }

    f1, f2, f3 := 0, 1, 1
    for i := 3; i <= n; i++ {
        f1 = f2
        f2 = f3
        f3 = (f1 + f2) % mod
    }
    return f3
}
```

### 2. [爬楼梯](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

``` cpp 
class Solution {
public:
    int numWays(int n) {
        vector<int> f(n + 10, 0);
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++) {
            f[i] = f[i - 1] % int(1e9 + 7)+ f[i - 2] % int(1e9 + 7);
        }
        return f[n] % int(1e9 + 7);
    }
};
```