[题目链接](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)  
[题解链接](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/jz11-fengwei2002-by-kycu-vudg/)

https://github.com/fengwei2002/algorithm

### 剑指 Offer 11. 旋转数组的最小数字

### 思路

把开头和结尾重复的元素去除之后，

区间具有二段性 

前面一段区间 `>= nums[0]`
后面一段区间 `< nums[0]`

利用二分寻找小于 `nums[0]` 的区间中最小的元素 

``` cpp
while (l < r) {
    int mid = (l + r) >> 1;
    if (nums[mid] >= nums[0]) r = mid; // 区间向左侧缩小
    else l = mid + 1;
}
```

### C++

``` cpp
class Solution {
public:
    int minArray(vector<int>& nums) {
        int n = nums.size() - 1;
        while (n > 0 && nums[n] == nums[0]) n--;
        if (nums[0] <= nums[n]) return nums[0];

        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        return nums[r];
    }
};
```

### GO

``` go
func minArray(numbers []int) int {
    n := len(numbers) - 1
    for n > 0 && numbers[n] == numbers[0] {
        n--;
    }
    if numbers[0] <= numbers[n] {
        return numbers[0]
    }

    l := 0
    r := n
    for l < r {
        mid := (l + r) >> 1;
        if numbers[mid] < numbers[0] {
            r = mid
        } else {
            l = mid + 1
        }
    }
    
    return numbers[r]
}
```