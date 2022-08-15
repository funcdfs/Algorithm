// Problem: 移掉K位数字
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1455/
// date: 2022-07-03 22:39:48
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for debug:
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
    
    string nums = ""; 
    cin >> nums; 
    
    int k = 0; 
    cin >> k; 
    
    // 移除 k 个数字之后，可以得到的最小的数字 
    
    string ans = "0";  
    
    for (int i = 0; i < nums.size(); i++) {
    	while (k > 0 && nums[i] < ans.back()) {
    		ans.pop_back(); 
    		k--; 
    	} 
    	ans += nums[i]; 
    } 
    
    while (k--) {
		ans.pop_back(); 
    }
    
    int i = 0; 
    while (i < ans.size() && ans[i] == '0') {
    	i++;  
    }
    
    if (i == ans.size()) {
    	ans = "0"; 
    } else {
    	ans = ans.substr(i); 
    } 
    
    cout << ans << endl; 
    
    return 0; 
    
    
    
    return 0;
}


/*

对于 nums 中的每一个数字，删除前面比 num[i] 大的所有的数字 

如果此时 k 仍然存在 
	此时的 num 数组非严格单调递增，减去的数字数量小于目标数量 k 
	那么就把 ans 中的后面 k 个字符全部删除 

最后统计前导零的个数
	如果前导零的个数等于字符串的长度，说明最后的结果就是 0 
	否则输出去除前导零之后的字符串 

*/