package main

import (
	"fmt"
)

func checkOnesSegment(s string) bool {
	// fmt.Println(len(s))
	for i := 1; i < len(s); i++ {
		// fmt.Printf("%c %c\n", s[i-1], s[i])
		if (s[i-1] == '0') && (s[i] == '1') {
			return false
		}
	}
	return true
}

func main() {
	str := "1001"
	fmt.Println(checkOnesSegment(str))
}
