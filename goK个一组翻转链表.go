// Definition for singly-linked list.
type ListNode struct {
    Val int
    Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
    // 创建一个哨兵节点
    dummy := &ListNode{Next: head}
    // 初始化前驱节点和当前节点
    pre := dummy
    cur := head
    // 循环直到链表末尾
    for cur != nil {
        // 找到下一组的起点和终点
        a := cur
        b := cur
        for i := 0; i < k; i++ {
            if b == nil {
                // 不足k个，直接返回
                return dummy.Next
            }
            b = b.Next
        }
        // 反转当前组，并返回反转后的头节点和尾节点
        newHead, newTail := reverse(a, b)
        // 将反转后的部分连接到前驱节点后面
        pre.Next = newHead
        // 更新前驱节点和当前节点为反转后的尾节点和下一组的起点
        pre = newTail
        cur = b
    }
    return dummy.Next
}

// 反转[a, b)之间的节点，并返回反转后的头节点和尾节点
func reverse(a, b *ListNode) (*ListNode, *ListNode) {
    var pre, cur, next *ListNode
    cur = a
    for cur != b {
        next = cur.Next
        cur.Next = pre
        pre = cur
        cur = next
    }
    return pre, a
}
