# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 反转[a, b)之间的节点
        def reverse(a, b):
            pre = None
            cur = a
            while cur != b:
                nxt = cur.next
                cur.next = pre
                pre = cur
                cur = nxt
            return pre
        
        # 创建哨兵节点
        dummy = ListNode()
        dummy.next = head
        
        # 初始化当前节点和前驱节点
        cur = dummy
        pre = dummy
        
        while cur:
            # 找到下一组k个节点的起点和终点
            for i in range(k):
                cur = cur.next
                if not cur:
                    return dummy.next
            
            # 记录下一组的起点
            nxt = cur.next
            
            # 反转当前组，并连接到前驱节点后面
            pre.next = reverse(pre.next, nxt)
            
            # 更新前驱节点和当前节点为反转后的尾节点和下一组的起点
            pre = cur = pre.next
        
        return dummy.next
