date: 2022-09-17

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220917235403.png)

找到每一个数字的后面的通过或操作可以得到的最大值 `t: []int`  
然后再找到每一个数字后面执行几个或运算就可以得到对应的最大值 `t[i]`

比赛的时候不会处理

---

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220918175044.png)

```
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> p(30, n); 
        vector<int> ans(n); 

        for (int i = n - 1; i >= 0; i--) {
            int t = i; 
            for (int j = 0; j < 30; j++) {
                if ((nums[i] >> j) & 1) { // 如果第 i 位置是 1，就使用第 i 位的
                    p[j] = i; 
                } else if (p[j] < n) { // 否则，如果第 i 位是 0， 那么如果第 j 位存在数字 1, 就更新一下 ans
                    t = max(t, p[j]); 
                }
            }

            ans[i] = t - i + 1; 
        } 

        return ans; 
    }
};
```