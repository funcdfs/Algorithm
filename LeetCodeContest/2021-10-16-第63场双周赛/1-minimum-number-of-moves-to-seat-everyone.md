[题目链接](https://leetcode.cn/problems/minimum-number-of-moves-to-seat-everyone/)

[题解链接](https://leetcode.cn/problems/minimum-number-of-moves-to-seat-everyone/solution/lc-fengwei2002-by-kycu-2owt/)

### Problem A - 使每位学生都有座位的最少移动次数

### 思路

纯纯猜题，因为它的位置是一一对应的，所以对于某个学生来说，如果离他较为近的有两个座位，分别为 `seats[left]` 和 `seats[right]`，则他只能从这两者之中选一个就坐，否则最后结果就不是最小
对于坐在最左边的学生来说，他只能坐在最左边，也就是 `student[0]` 只能选择 `seats[right]`, 因为 `seats[left]` 为空

运用数学归纳法，就可以发现每个学生都只能选择 `seats[right]`, 使得结果唯一

### 代码

``` cpp
// https://github.com/fengwei2002/algorithm

class Solution {
   public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        // 排序
        int n = seats.size();
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans += abs(seats[i] - students[i]);
        }
        // 统计差值的和
        
        return ans;
    }
};

// seats[i] 是第 i 个座位的位置。
// students[j] 是第 j 位学生的位置。

// 请你返回使所有学生都有座位坐的 最少移动次数 
```