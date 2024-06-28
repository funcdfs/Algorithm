// link: https://codeforces.com/contest/1685/problem/A A. Circular Local MiniMax
// time: 2024/6/28 14:32:10 https://github.com/funcdfs
// #region main
package main; import ("bufio"; "fmt"; "os"; "sort"; ); var _in, _out = new(bufio.Reader), new(bufio.Writer);
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); testCaseCnt := input[int](); for i := 0; i < testCaseCnt; i++ { solve(i + 1); } }
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }; func println[T any](x ...T) { print(" ", "\n", x...) };
func inputSlice[T any](length int) []T { data := make([]T, length); for i := 0; i < length; i++ { data[i] = input[T](); }; return data; }
func print[T any](sep, end string, x ...T) { for i := range x { fmt.Fprint(_out, x[i]); if i == len(x)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep); } } }
// #endregion main
// ---------------------------------------------------------------

func solve(_case int) {

	n := input[int]()
	a := inputSlice[int](n)

	// \/\/\/...\/\/\/. 首尾相接

	if n%2 == 1 {
		println("NO")
	} else {
		sort.Slice(a, func(i, j int) bool {
			return a[i] < a[j]
		})
		b := make([]int, 0, n)
		for i := 0; i < n/2; i++ {
			b = append(b, a[i])
			b = append(b, a[len(a)-i-1])
		}
		cnt := make(map[int]int, n)
		for i := range b {
			cnt[b[i]] += 1
			if cnt[b[i]] > n/2 {
				println("NO")
				return
			}
		}
		println("YES")
		println(b...)
	}
}

// ---------------------------------------------------------------
