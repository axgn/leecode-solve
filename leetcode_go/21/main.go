package main

import . "../leetcode"

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	res := &ListNode{}
	list1 = &ListNode{Val: -101, Next: list1}
	list2 = &ListNode{Val: -101, Next: list2}
	i := res
	for {
		if list1.Val < list2.Val {
			i.Next = list1
			list1 = list1.Next
		} else {
			i.Next = list2
			list2 = list2.Next
		}
		i = i.Next
		if list1 == nil || list2 == nil {
			break
		}
	}
	if list1 != nil {
		i.Next = list1
	} else {
		i.Next = list2
	}
	return res.Next.Next.Next
}
