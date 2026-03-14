package main

import "fmt"

func conver_str(tmp []byte) string {
	n := len(tmp)
	res := make([]byte, n)

	res[0] = tmp[n-1] + 'a'

	next := [3][2]byte{
		{'b', 'c'},
		{'a', 'c'},
		{'a', 'b'},
	}

	for i := 1; i < n; i++ {
		prev := res[i-1] - 'a'
		res[i] = next[prev][tmp[n-1-i]]
	}

	return string(res)
}

func getHappyString(n int, k int) string {
	cnt := n
	k = k - 1
	str := make([]byte, 0, n)
	for ; cnt > 0; cnt-- {
		if k > 0 {
			var tmp int
			if cnt > 1 {
				tmp = k % 2
				k /= 2
			} else {
				tmp = k % 3
				k /= 3
			}
			str = append(str, byte(tmp))
		} else {
			str = append(str, byte(0))
		}
	}
	if k > 0 {
		return ""
	}

	return conver_str(str)
}

func main() {
	fmt.Println(getHappyString(10, 100))
}
