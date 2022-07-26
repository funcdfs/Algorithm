// Problem: 丑数
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/58/
// date: 2022-04-09 19:41:27
// Memory Limit: 64 MB
// Time Limit:   1000 ms


// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // 

class Solution {
public:
    int getUglyNumber(int n) {
        // 把只包含 2 3 5 的数字叫做丑数
        // 求第 n 个丑数的 value  
        vector<int> q(1, 1); 
        // 定义一个序列，刚开始只包含 1 
        
        int i = 0, j = 0, k = 0; 
        while (q.size() < n) {
        	int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5)); 
        	q.push_back(t); 
        	if (q[i] * 2 == t) i++; 
        	if (q[j] * 3 == t) j++; 
        	if (q[k] * 5 == t) k++; 
        }
        
        return q.back(); 
    } 
};


/*

三路归并

所有包含因子 2 的所有丑数 i
所有包含因子 3 的所有丑数 j
所有包含因子 5 的所有丑数 k

把第一个序列的每个数字除以 2 
把第二个序列的每个数字除以 3 
把第三个序列的每个数字除以 5

除完之后的序列，这三个都是一样的， 并且恰好是整个的丑数序列 

所以就可以用之前计算得到的丑数序列，然后每次决定放 i j 还是 k 

*/