/**
 * author:  https://github.com/funcdfs
 * problem: https://www.acwing.com/problem/content/5579/
 * created: 5/13/2024, 1:09:32 PM
**/

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func authorFuncdfs(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	if c >= a && c <= b {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func main() { authorFuncdfs(bufio.NewReader(os.Stdin), os.Stdout) }
