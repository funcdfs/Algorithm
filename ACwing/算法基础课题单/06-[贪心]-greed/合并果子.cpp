// Problem: 合并果子
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/150/
// date: 2022-02-12 22:24:41
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// 读入所有的果子堆
// 设计合并方案，使得耗费的体力最小，输出这个最小的体力耗费值
// 消耗的体力等于两堆果子的质量之和

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 将更小的值放入完全二叉树的深度更深的地方
// 输出完全二叉树路径之和

int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> heap;
	while (n--) {
		int x;
		cin >> x;
		heap.push(x);
	}
	
	int ans = 0;
	while (heap.size() > 1) {
		int a = heap.top(); heap.pop();
		int b = heap.top(); heap.pop();
		ans += a + b;
		heap.push(a + b);
	}
	
	printf("%d\n", ans);
}









