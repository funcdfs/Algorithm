// link: https://codeforces.com/contest/677/problem/A A. Vanya and Fence
// time: 2024/9/14 18:05:49 https://github.com/funcdfs

// #region main
package main; import ( "bufio"; "fmt"; "os"; ); var _in, _out = new(bufio.Reader), new(bufio.Writer)
func _github_funcdfs[T any](sep, end string, arr ...T) { for idx := range arr { fmt.Fprint(_out, arr[idx]); if idx == len(arr)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep) } } }
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); solve() }
func input      [T any] ()           T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice [T any] (size int) []T { data := make([]T, size); for idx := 0; idx < size; idx++ { data[idx] = input[T](); }; return data }
func print      [T any] (arr ...T)     { _github_funcdfs("", "", arr...) }
func println    [T any] (arr ...T)     { _github_funcdfs(" ", "\n", arr...) }
// #endregion main


// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	n, h := input[int](), input[int]()
	a := inputSlice[int](n) 
	
	cnt := 0
	for i := range a {
		if a[i] <= h {
			cnt += 1
		} else {
			cnt += 2
		}
	}

	println(cnt)

}

// ----------------------------- /* End of useful functions */ -------------------------------