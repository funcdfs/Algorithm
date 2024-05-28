// created: 2024/5/28 23:28:51 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc161/tasks/abc161_c

package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	var n, k uint64
	fmt.Fscan(_in, &n, &k)
	if n > k {
		x := n / k
		if n%k > 0 {
			x += 1
		}
		fmt.Fprintln(_out, x*k-n)
	} else {
		k = k - (k-1)*n
		x := n / k
		if n%k > 0 {
			x += 1
		}
		fmt.Fprintln(_out, x*k-n)
	}

}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	solve(_in, _out)
}
