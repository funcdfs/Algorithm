// created: 2024/5/31 12:05:30 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1703/problem/F

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// region solve
// --------------------------------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := 0
	fmt.Fscan(_in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(_in, &a[i])
	}
	idxs := make([]int, 0)
	for i := range a {
		if a[i] < i+1 {
			idxs = append(idxs, i+1)
		}
	}
	// fmt.Fprintln(os.Stderr, a, idxs)
	ans := int64(0)
	for _, id := range idxs {
		ai := a[id-1]
		ans += int64(sort.Search(len(idxs), func(i int) bool {
			return idxs[i] >= ai
		})) // idxs[i] < a[i] cnt
		// fmt.Fprintln(os.Stderr, ai, ans)
	}
	fmt.Fprintln(_out, ans)
}

// --------------------------------------------------------------------------
// endregion solve
func Iota(startVal int, length int) []int {
	res := make([]int, length)
	for i := 0; i < length; i++ {
		res[i] = startVal + i
	}
	return res
}
func preProcess() {

}

// region main
func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	preProcess()
	var testCaseCnt int
	fmt.Fscan(_in, &testCaseCnt)
	for i := 1; i <= testCaseCnt; i++ {
		solve(i, _in, _out)
	}
}

// endregion main
