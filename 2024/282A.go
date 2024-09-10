// link: https://codeforces.com/contest/282/problem/A A. Bit++
// time: 2024/9/10 13:19:36 https://github.com/funcdfs

// #region main
package main; import ( "bufio"; "fmt"; "os"; ); var _in, _out = new(bufio.Reader), new(bufio.Writer)
func _print_config[T any](sep, end string, arr ...T) { for idx := range arr { fmt.Fprint(_out, arr[idx]); if idx == len(arr)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep) } } }
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); solve() }
func input      [T any] ()           T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice [T any] (size int) []T { data := make([]T, size); for idx := 0; idx < size; idx++ { data[idx] = input[T](); }; return data }
func print      [T any] (arr ...T)     { _print_config(" ", " ", arr...) }
func println    [T any] (arr ...T)     { _print_config(" ", "\n", arr...) }
// #endregion main


// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	baseVal := 0
	t := input[int]()
	
	for i := 0; i < t; i++ {
		s := input[[]byte]()
		if s[1] == '+' {
			baseVal++
		} else if s[1] == '-' {
			baseVal--
		}
	}

	println(baseVal)

}

// ----------------------------- /* End of useful functions */ -------------------------------