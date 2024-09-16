// link: https://codeforces.com/contest/474/problem/A A. Keyboard
// time: 2024/9/16 10:25:51 https://github.com/funcdfs

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

	op := input[[]byte]()
	s := input[[]byte]()
	keyboard := []byte("`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./")
	hs := make(map[byte]int)
	for i := range keyboard {
		hs[keyboard[i]] = i
	}
	
	ans := make([]byte, 0, len(s))
	if op[0] == 'R' {
		// move to right
		for i := range s {
			ans = append(ans, keyboard[hs[s[i]] - 1])
		}
	} else if op[0] == 'L' {
		// move to left
		for i := range s {
			ans = append(ans, keyboard[hs[s[i]] + 1])
		}
	}

	println(string(ans))

}

// ----------------------------- /* End of useful functions */ -------------------------------