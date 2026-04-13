package main

import . "../leetcode"

func detectCycle(head *ListNode) *ListNode {
	fast := head
	slow := head
	for {
		if fast == nil || fast.Next == nil {
			return nil
		}
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			temp := head
			for temp != slow {
				temp = temp.Next
				slow = slow.Next
			}
			break
		}
	}
	return slow
}
