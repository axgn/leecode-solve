package main

func canPartitionGrid(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	rowsum := make([]int, m)
	colsum := make([]int, n)
	for i, row := range grid {
		for j, v := range row {
			rowsum[i] += v
			colsum[j] += v
		}
	}
	return true
}
