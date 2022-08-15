// Problem: 蒙斯特
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/699/
// date: 2022-07-26 10:18:31
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <cstring> 

using namespace std; 

const int N = 110; 

int n; 
string cards[N]; 

int main() {
	int T; 
	cin >> T; 
	
	for (int C = 1; C <= T; C++) {
		cin >> n; 
		getchar(); 
		for (int i = 0; i < n; i++) {
			getline(cin, cards[i]); 
		} 
		// 将每一行读入 cards 中
		
		int ans = 0; 
		for (int i = 1; i < n; i++) {
			if (cards[i] < cards[i - 1]) { // 如果当前数字小于当前数字的前面的，那么应该把他放在前面
				for (int j = i; j > 0; j--) { // 执行把这个小元素放到该放的位置的过程
					if (cards[j] < cards[j - 1]) {
						swap(cards[j], cards[j - 1]); 
					}
				}
				ans++; 
			}
		}
		
		printf("Case #%d: %d\n", C, ans); 
	}
	
	return 0; 
}

/*

按照字母顺序对卡片进行排序，这样就可以在短时间内找到他想要的卡片

但是他自己不能整理这些卡片

雇佣了一个机器人，这个机器人移动卡片一次就收取 1 美元

移动的逻辑：
	会扫描直到最后一张卡片，并一个一个移动卡片，直到所有卡牌按照字典顺序从上到下排序
	
输出使用这个机器人需要的费用


2
2
Oksana Baiul
Michelle Kwan
3
Elvis Stojko
Evgeni Plushenko
Kristi Yamaguchi

Case #1: 1
Case #2: 0

*/