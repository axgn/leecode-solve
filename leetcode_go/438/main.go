package main

func findAnagrams(s string, p string) []int {
	index := []int{}
	cntmap := make(map[byte]int)
	for i := 0; i < len(p); i++ {
		cntmap[p[i]]++
	}
	return index
}
