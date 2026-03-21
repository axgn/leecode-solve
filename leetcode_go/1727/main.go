package main

func largestSubmatrix(matrix [][]int) int {
	col := len(matrix[0])
	height := make([]int, col)
	height_idx := make([]int, col)
	for i := 0; i < col; i++ {
		height_idx[i] = i
	}
	_nonZeros := make([]int, col)
	max := 0
	for _, row := range matrix {
		zeros := height_idx[:0]
		nonZeros := _nonZeros[:0]
		for _, j := range height_idx {
			if row[j] == 0 {
				height[j] = 0
				zeros = append(zeros, j)
			} else {
				height[j] += 1
				nonZeros = append(nonZeros, j)
			}
		}
		height_idx = append(zeros, nonZeros...)
		for i := len(zeros); i < col; i++ {
			tmp := (col - i) * height[height_idx[i]]
			if tmp > max {
				max = tmp
			}
		}
	}
	return max
}
