package main

import (
	. "../leetcode"
)

func getIntersectionNode2(headA, headB *ListNode) *ListNode {
	setA := make(map[*ListNode]struct{})
	for headA != nil {
		setA[headA] = struct{}{}
		headA = headA.Next
	}
	for headB != nil {
		if _, ok := setA[headB]; ok {
			return headB
		}
		headB = headB.Next
	}
	return nil
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	tempA, tempB := headA, headB
	for headA != nil && headB != nil {
		if tempA != nil {
			tempA = tempA.Next
		} else {
			headB = headB.Next
		}
		if tempB != nil {
			tempB = tempB.Next
		} else {
			headA = headA.Next
		}
		if headA == headB {
			return headA
		}
	}
	return nil
}

func main() {

}
