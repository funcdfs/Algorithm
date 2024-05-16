/**
 * author:  https://github.com/funcdfs
 * problem: https://www.acwing.com/problem/content/787/
 * created: 2024/5/15 21:13:08
**/

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func leetcode {
	hs := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		hs[nums[i]] = i
		if v, ok := hs[target - nums[i]]; ok {
			return []int{hs[target - nums[i]], i}
		}
	}
	return nil
}

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	n := 0
	fmt.Fscan(_in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(_in, &a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	for i := 0; i < n; i++ {
		fmt.Fprint(_out, a[i], " ")
	}
	fmt.Fprintln(_out)
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	solve(_in, _out)
}
