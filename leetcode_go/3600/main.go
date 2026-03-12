package main

import (
	"math"
	"slices"
)

type FindUnion struct {
	value []int
	cnt   int
}

func getFindUnion(num int) *FindUnion {
	value := make([]int, num)
	for i := range value {
		value[i] = i
	}
	return &FindUnion{value, num}
}

func (c *FindUnion) find(x int) int {
	if x != c.value[x] {
		c.value[x] = c.find(c.value[x])
	}
	return c.value[x]
}

func (c *FindUnion) merge(from, to int) bool {
	x, y := c.find(from), c.find(to)
	if x == y {
		return false
	}
	c.value[x] = y
	c.cnt--
	return true
}

func compare(edge1 []int, edge2 []int) int {
	return edge2[2] - edge1[2]
}

func maxStability(n int, edges [][]int, k int) int {
	uf := getFindUnion(n)
	Alluf := getFindUnion(n)
	minS1 := math.MaxInt
	for _, v := range edges {
		x, y, val, must := v[0], v[1], v[2], v[3]
		if must == 1 {
			if !uf.merge(x, y) {
				return -1
			}
			minS1 = min(minS1, val)
		}
		Alluf.merge(x, y)
	}
	if Alluf.cnt != 1 {
		return -1
	}

	if uf.cnt == 1 {
		return minS1
	}

	slices.SortFunc(edges, compare)

	a := []int{}
	for _, e := range edges {
		x, y, s, must := e[0], e[1], e[2], e[3]
		if must == 0 && uf.merge(x, y) {
			a = append(a, s)
		}
	}

	m := len(a)
	ans := min(minS1, a[m-1]*2)
	if k < m {
		ans = min(ans, a[m-1-k])
	}

	return ans
}
