题解链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/jz-fengwei2002-yuan-di-zhi-huan-by-kycu-ujwn/

题目链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

- 排序后，比对前后值，找到重复数字，
- 还可以使用 hashmap 用来存放数字的出现次数，等于 2 的时候结束程序
- 原地置换

主要思想是把每个数放到对应的位置上，即让 $nums[i] = i$。

从前往后遍历数组中的所有数，假设当前遍历到的数是 $nums[i]=x$，那么：

- 如果 $x \neq i \;\; \&\& \;\; nums[x] == x$，则说明 $x$ 出现了不止一次，直接返回 $x$ 即可；
- 如果 $nums[x] \neq x$，那我们就把 $x$ 交换到正确的位置上，即 $swap(nums[x], nums[i])$，交换完之后如果 $nums[i] \neq i$，则重复进行该操作。由于每次交换都会将一个数放在正确的位置上，所以 $swap$ 操作最多会进行 $n$ 次，不会发生死循环。
- 循环结束后，如果没有找到任何重复的数，则返回 $-1$

``` go 
func findRepeatNumber(nums []int) int {
    for i := 0; i < len(nums); i++ {
        for nums[i] != i {
            if nums[nums[i]] == nums[i] {
                return nums[i]
            } else {
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
            }
        }
    }
    return -1;
}
```


``` c++
class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                } else {
                    swap(nums[nums[i]], nums[i]);
                }
            }
        }
        return -1;
    }
};
```