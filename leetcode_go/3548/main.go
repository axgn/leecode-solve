package main

import "slices"

func canPartitionGrid(grid [][]int) bool {
	total := 0
	for _, row := range grid {
		for _, x := range row {
			total += x
		}
	}

	check := func(a [][]int) bool {
		m, n := len(a), len(a[0])
		f := func() bool {
			has := map[int]bool{0: true}
			s := 0
			for i, row := range a[:m-1] {
				for j, x := range row {
					s += x
					if i > 0 || j == 0 || j == n-1 {
						has[x] = true
					}
				}
				if n == 1 {
					if s*2 == total || s*2-total == a[0][0] || s*2-total == row[0] {
						return true
					}
					continue
				}
				if has[s*2-total] {
					return true
				}
				if i == 0 {
					for _, x := range row {
						has[x] = true
					}
				}
			}
			return false
		}
		if f() {
			return true
		}
		slices.Reverse(a)
		return f()
	}

	return check(grid) || check(rotation90(grid))
}

func rotation90(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	ret := make([][]int, n)
	for i := range ret {
		ret[i] = make([]int, m)
	}
	for i, row := range grid {
		for j, v := range row {
			ret[j][m-1-i] = v
		}
	}
	return ret
}
