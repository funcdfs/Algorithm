// link: https://codeforces.com/contest/1793/problem/C C. Dora and Search
// time: 2024/6/25 16:51:51 https://github.com/funcdfs

package main
import ("bufio"; "fmt"; "log"; "os";)

// ---------------------------------------------------------------

func solve(_case int) { // log.Println("# CASE: ", _case)

	n := input[int]()
	a := inputSlice[int](n)

	l, r, lVal, rVal := 0, n-1, 1, n
	for l <= r {
		if a[l] == lVal || a[l] == rVal {
			if a[l] == lVal {
				lVal++
			}
			if a[l] == rVal {
				rVal--
			}
			l++
		} else if a[r] == lVal || a[r] == rVal {
			if a[r] == lVal {
				lVal++
			}
			if a[r] == rVal {
				rVal--
			}
			r--

		} else {
			break
		}
	}
	if l <= r {
		println(l+1, r+1)
	} else {
		println(-1)
	}

}

// ---------------------------------------------------------------

// #region fastIO

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	log.SetFlags(log.Lshortfile)
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice[T any](length int) []T {
	data := make([]T, length)
	for i := 0; i < length; i++ {
		data[i] = input[T]()
	}
	return data
}
func print[T any](sep, end string, x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i])
		if i == len(x)-1 {
			fmt.Fprint(_out, end)
		} else {
			fmt.Fprint(_out, sep)
		}
	}
}
func println[T any](x ...T) { print(" ", "\n", x...) }

// #endregion fastIO
