package main

import . "../leetcode"

func getmid(left *ListNode, right *ListNode) *ListNode {
	fast := left
	slow := left
	for {
		if fast != right && fast.Next != right {
			fast = fast.Next.Next
			slow = slow.Next
		} else {
			break
		}
	}
	return slow
}

func buildTree(left *ListNode, right *ListNode) *TreeNode {
	if left == right {
		return nil
	}
	midnode := &TreeNode{}
	mid := getmid(left, right)
	midnode.Val = mid.Val
	midnode.Left = buildTree(left, mid)
	midnode.Right = buildTree(mid.Next, right)
	return midnode
}

func sortedListToBST(head *ListNode) *TreeNode {
	res := buildTree(head, nil)
	return res
}
