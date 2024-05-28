package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	n, m := 0, 0
	fmt.Fscan(_in, &n, &m)
	// n 成员 m 新人
	/*
		      4 5
		1 2   3 3
		1 2   2 1
		2 1   0 0
	*/
	ans := 0
	for n > 0 && m > 0 {
		if n > m {
			n, m = m, n
		}
		diff := m - n
		if diff == 0 {
			diff = 1
		}
		diff = Min(diff, n, m)
		// fmt.Fprint(os.Stderr, "diff: ", diff)
		n -= 1 * diff
		m -= 2 * diff
		if n >= 0 && m >= 0 {
			ans += diff
		}
	}
	fmt.Fprintln(_out, ans)
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	solve(_in, _out)
}

func Min[T int | int64 | float32 | float64 | string](args ...T) T {
	res := args[0]
	for i := 1; i < len(args); i++ {
		if args[i] < res {
			res = args[i]
		}
	}
	return res
}
