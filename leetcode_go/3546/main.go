package main

func check(v []int) bool {
	size := len(v)
	for i := 1; i < size; i++ {
		v[i] += v[i-1]
	}
	for i := 0; i < size-1; i++ {
		if v[i] == v[size-1]-v[i] {
			return true
		}
	}
	return false
}

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
	if check(rowsum) || check(colsum) {
		return true
	}
	return false
}

func main() {

}
