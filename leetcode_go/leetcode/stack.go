package leetcode

import "fmt"

type stack[T any] interface {
	push(ele T)
	pop() T
}

type List[T any] struct {
	arr []T
}

func (list *List[T]) push(ele T) {
	list.arr = append(list.arr, ele)
}

func (list *List[T]) pop() T {
	temp := list.arr[len(list.arr)-1]
	list.arr = list.arr[:len(list.arr)-1]
	return temp
}

func main() {
	var s stack[int]
	s = &List[int]{arr: []int{1, 2, 3}}
	s.push(5)
	fmt.Println(s.pop())
	fmt.Println(s.pop())
	fmt.Println(s.pop())
	fmt.Println(s.pop())
}
