// created: 2024/6/3 22:28:54 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1976/problem/A

package main

import (
	"bufio"
	"fmt"
	"os"
)

// region solve ----------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	n := 0
	fmt.Fscan(_in, &n)
	s := make([]byte, n)
	fmt.Fscan(_in, &s)

	check := func() bool {
		cnt := 0
		pre := byte('0')
		preC := byte('a')
		for i := range s {
			if s[i] >= '0' && s[i] <= '9' {
				cnt += 1
				if s[i] >= pre {
					pre = s[i]
				} else {
					return false
				}
			} else if s[i] >= 'a' && s[i] <= 'z' {
				cnt += 1
				if i+1 < n && !(s[i+1] >= 'a' && s[i+1] <= 'z') {
					return false
				}
				if s[i] >= preC {
					preC = s[i]
				} else {
					return false
				}
			}
		}
		if cnt != len(s) {
			return false
		}
		return true
	}
	if check() == true {
		fmt.Fprintln(_out, "YES")
	} else {
		fmt.Fprintln(_out, "NO")
	}
}

// endregion solve --------------------------------------------------

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	var testCaseCnt int
	fmt.Fscan(_in, &testCaseCnt)
	for i := 1; i <= testCaseCnt; i++ {
		solve(i, _in, _out)
	}
}

/*

 */
