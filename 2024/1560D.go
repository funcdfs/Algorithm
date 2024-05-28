// created: 2024/5/28 22:22:12 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1560/problem/D

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var power = make([]string, 0)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	s := ""
	fmt.Fscan(_in, &s)
	ans := 99

	for i := 0; i < len(power); i++ {
		t := power[i]
		cnt := 0
		for j := 0; j < len(s); j++ {
			if cnt < len(t) && t[cnt] == s[j] {
				cnt += 1
			}
		}
		ans = Min(ans, len(s)+len(t)-2*cnt)
	}

	fmt.Fprintln(_out, ans)
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	for i := 0; i <= 62; i++ {
		t := strconv.FormatInt(1<<i, 10)
		power = append(power, t)
	}
	// fmt.Fprintln(os.Stderr, power)
	var TT int
	for fmt.Fscan(_in, &TT); TT > 0; TT-- {
		solve(_in, _out)
	}
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
