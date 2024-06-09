// created: 2024/6/4 12:06:28 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1837/problem/C

package main

import (
	"bufio"
	"fmt"
	"os"
)

// region solve ----------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	ss := ""
	fmt.Fscan(_in, &ss)
	s := []byte(ss)
	ans := make([]byte, len(s))
	copy(ans, s)
	
	if s[0] == '?' {
		ans[0] = '0'
	}
	for i := 1; i < len(s); i++ {
		if s[i] == '?' {
			ans[i] = ans[i-1]
		}
	}
	fmt.Fprintln(_out, string(ans))
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
