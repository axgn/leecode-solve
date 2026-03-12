package main

import "math/bits"

func bitwiseComplement(n int) int {
	if n == 0 {
		return 1
	}
	length := bits.Len(uint(n))
	mask := (1 << length) - 1
	return n ^ mask
}

func bitwiseComplement2(n int) int {
	i := 2
	for ; i <= n; i = i << 1 {
	}
	return i - n - 1
}
