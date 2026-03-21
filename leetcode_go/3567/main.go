package main

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
		}
	}

}

func main() {

}
