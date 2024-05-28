// created: 2024/5/29 00:40:02 author:  https://github.com/funcdfs 
// problem: https://codeforces.com/contest/1490/problem/E

package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	n := 0
	fmt.Fscan(_in, &n) 
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(_in, &a[i]) 
	}
	
	
	
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	var TT int
	for fmt.Fscan(_in, &TT); TT > 0; TT-- {
		solve(_in, _out)
	}
}