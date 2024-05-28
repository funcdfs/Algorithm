/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1698/problem/C
 * created: 2024/5/28 20:46:37
**/
package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	n := 0
	fmt.Fscan(_in, &n)
	a, pos, neg := make([]int, 0), make([]int, 0), make([]int, 0)
	for i := 0; i < n; i++ {
		x := 0
		fmt.Fscan(_in, &x)
		if x > 0 {
			pos = append(pos, x)
		} else if x < 0 {
			neg = append(neg, x)
		} else {
			if len(a) < 2 {
				a = append(a, x)
			}
		}
	}
	if len(pos) >= 3 || len(neg) >= 3 {
		fmt.Fprintln(_out, "NO")
		return
	}
	for i := range pos {
		a = append(a, pos[i])
	}
	for i := range neg {
		a = append(a, neg[i])
	}
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			for k := j + 1; k < len(a); k++ {
				flag := false
				for l := range a {
					if a[i]+a[j]+a[k] == a[l] {
						flag = true
					}
				}
				if flag == false {
					fmt.Fprintln(_out, "NO")
					return
				}
			}
		}
	}
	fmt.Fprintln(_out, "YES")
	return
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
