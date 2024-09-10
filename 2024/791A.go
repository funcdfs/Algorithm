// link: https://codeforces.com/contest/791/problem/A A. Bear and Big Brother
// time: 2024/9/10 14:05:10 https://github.com/funcdfs

// #region main
package main; import ( "bufio"; "fmt"; "os"; ); var _in, _out = new(bufio.Reader), new(bufio.Writer)
func _print_config[T any](sep, end string, arr ...T) { for idx := range arr { fmt.Fprint(_out, arr[idx]); if idx == len(arr)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep) } } }
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); solve() }
func input      [T any] ()           T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice [T any] (size int) []T { data := make([]T, size); for idx := 0; idx < size; idx++ { data[idx] = input[T](); }; return data }
func print      [T any] (arr ...T)     { _print_config("", "", arr...) }
func println    [T any] (arr ...T)     { _print_config(" ", "\n", arr...) }
// #endregion main


// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	a, b := input[int](), input[int]()
	// a <= b 

	cnt := 0 
	for a <= b {
		a *= 3 
		b *= 2
		cnt += 1 
	}

	println(cnt)

}

// ----------------------------- /* End of useful functions */ -------------------------------