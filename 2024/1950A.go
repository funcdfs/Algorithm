// created: 2024/5/31 15:39:08 author:  https://github.com/funcdfs 
// problem: https://codeforces.com/contest/1950/problem/A


package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

// region solve
// --------------------------------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	a, b, c := 0, 0, 0
	fmt.Fscan(_in, &a, &b, &c) 
	if a < b && b < c {
		fmt.Fprintln(_out, "STAIR") 
	} else if a < b && b > c {
		fmt.Fprintln(_out, "PEAK") 
	} else  {
		fmt.Fprintln(_out, "NONE") 
	}
}

// --------------------------------------------------------------------------
// endregion solve

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
	leftData, _ := io.ReadAll(_in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("!!!!!!!DATA INPUT ERROR!!!!!!! \n\n" + s + "\n")
	}
}

// endregion main
