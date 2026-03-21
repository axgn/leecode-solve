package main

func reverseSubmatrix(grid [][]int, x int, y int, k int) [][]int {
	for i := x; i < x+k/2; i++ {
		for j := y; j < y+k; j++ {
			temp := 2*x + k - i - 1
			grid[i][j], grid[temp][j] = grid[temp][j], grid[i][j]
		}
	}
	return grid
}
func main() {

}
