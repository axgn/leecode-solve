package main

func solveQueries(nums []int, queries []int) []int {
	posmap := make(map[int][]int)
	posmap2 := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		posmap2[i] = len(posmap[nums[i]])
		posmap[nums[i]] = append(posmap[nums[i]], i)
	}
	n := len(queries)
	res := make([]int, n)
	for i, value := range queries {
		arr := posmap[nums[value]]
		if len(arr) <= 1 {
			res[i] = -1
			continue
		}
		pos := posmap2[value]
		a := arr[(pos+1)%len(arr)]
		b := arr[(pos-1+len(arr))%len(arr)]
		m := len(nums)
		res[i] = min((a-value+m)%m, (value-b+m)%m)
	}
	return res
}
