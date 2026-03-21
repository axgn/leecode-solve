package main

func numberOfSubmatrices(grid [][]byte) (ans int) {
	m, n := len(grid), len(grid[0])
	sum := make([][]int, m+1)
	sum[0] = make([]int, n+1)
	min_n := n
	charmap := map[byte]int{'X': -1, 'Y': 1, '.': 0}
	for i, row := range grid {
		sum[i+1] = make([]int, n+1)
		for j, x := range row {
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + charmap[x]
			if x == 'X' || x == 'Y' {
				min_n = min(min_n, j)
			}
			if sum[i+1][j+1] == 0 && (j >= min_n) {
				ans++
			}
		}
	}
	return
}
