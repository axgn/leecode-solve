package main

import (
	"math"
	"slices"
)

func minAbsDiff(grid [][]int, k int) [][]int {
	temp := make([]int, k*k)
	row := len(grid)
	col := len(grid[0])
	ans := make([][]int, row-k+1)
	for i := range ans {
		ans[i] = make([]int, col-k+1)
		for j := range ans[i] {
			a := temp[:0]
			for _, v := range grid[i : i+k] {
				a = append(a, v[j:j+k]...)
			}
			slices.Sort(a)
			res := math.MaxInt
			for i := 1; i < len(a); i++ {
				if a[i]-a[i-1] > 0 {
					res = min(res, a[i]-a[i-1])
				}
			}
			if res != math.MaxInt {
				ans[i][j] = res
			}
		}
	}
	return ans
}

func main() {

}
