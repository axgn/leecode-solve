package main

import . "../leetcode"

func hasCycle(head *ListNode) bool {
	fast := head
	slow := head
	for {
		if fast == nil || fast.Next == nil {
			return false
		}
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			break
		}
	}
	return true
}
