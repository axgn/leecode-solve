package main

import "fmt"

func findAnagrams(s string, p string) []int {
	index := []int{}
	cntmap := make(map[byte]int)
	if len(s) < len(p) {
		return index
	}
	for i := 0; i < len(p); i++ {
		cntmap[p[i]]++
		cntmap[s[i]]--
	}
	for key, v := range cntmap {
		if v == 0 {
			delete(cntmap, key)
		}
	}
	if len(cntmap) == 0 {
		index = append(index, 0)
	}
	for i := len(p); i < len(s); i++ {
		cntmap[s[i-len(p)]]++
		if cntmap[s[i-len(p)]] == 0 {
			delete(cntmap, s[i-len(p)])
		}
		cntmap[s[i]]--
		if cntmap[s[i]] == 0 {
			delete(cntmap, s[i])
		}
		if len(cntmap) == 0 {
			index = append(index, i-len(p)+1)
		}
	}
	return index
}

func main() {
	s, p := "baa", "aa"
	fmt.Println(findAnagrams(s, p))
}
