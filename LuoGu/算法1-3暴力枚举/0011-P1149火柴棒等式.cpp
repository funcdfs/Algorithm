// Problem: P1149 [NOIP2008 提高组] 火柴棒等式
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1149
// date: 2022-02-10 13:23:29
// Memory Limit: 125 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>
// for debug:
#define d(a)  // cout << #a << " = " << a << ' ';
#define dline // cout << " ----- " << endl;
#define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int x[1001] = {6,2,5,5,4,5,6,3,7,6};
// 定义 0 - 9的火柴棒子的个数
int b[4];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 给定 n 根火柴棍 可以拼出多少 a + b = c 的等式
    int i = 0;
    cin >> i;
    n
    
    return 0;
}










void reverse(ListNode *root, int k) {
	auto dummy = new ListNode(-1);
	dummy->next = head;
	
	for (auto p = dummy;; ) {
		auto q = p;
		for (int i = 0; i < k && q; i++) q = q->next;
		if (!q) break;
		
		auto a = p->next;
		// a 指向每一组的第一个元素
		auto b = a->next;
		
		// 一共交换 k - 1 个相邻的位置， 所以走 k - 1 步
		for (int i = 0; i < k - 1; i++) {
			auto c = b->next;
			b->next = a;
			a = b, b = c;
		}
		// 把 k 个节点内部的边反转操作做完了
		
		// a 位于反转之后的最后一个位置
		auto c = p->next;
		p->next = a;
		// b 位于反转之后的第一个位置
		c->next = b;
		
		// 然后 p 跳到 c 的位置
		p = c; 
	}
	
	return dummy->next;
}












