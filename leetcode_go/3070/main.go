package main

func countSubmatrices(grid [][]int, k int) int {
	result := 0
	if grid[0][0] <= k {
		result += 1
	}
	for i := 1; i < len(grid); i++ {
		grid[i][0] += grid[i-1][0]
		if grid[i][0] <= k {
			result += 1
		}
	}
	for j := 1; j < len(grid[0]); j++ {
		grid[0][j] += grid[0][j-1]
		if grid[0][j] <= k {
			result += 1
		}
	}
	for i := 1; i < len(grid); i++ {
		for j := 1; j < len(grid[0]); j++ {
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]
			if grid[i][j] <= k {
				result += 1
			}
		}
	}
	return result
}
