// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
  // 创建一个哨兵节点
  let dummy = new ListNode(0, head);
  // 初始化前驱节点和当前节点
  let pre = dummy;
  let cur = head;
  // 循环直到链表末尾
  while (cur) {
    // 找到下一组的起点和终点
    let a = cur;
    let b = cur;
    for (let i = 0; i < k; i++) {
      if (!b) {
        // 不足k个，直接返回
        return dummy.next;
      }
      b = b.next;
    }
    // 反转当前组，并返回反转后的头节点和尾节点
    let [newHead, newTail] = reverse(a, b);
    // 将反转后的部分连接到前驱节点后面
    pre.next = newHead;
    // 更新前驱节点和当前节点为反转后的尾节点和下一组的起点
    pre = newTail;
    cur = b;
  }
  return dummy.next;
};

// 反转[a, b)之间的节点，并返回反转后的头节点和尾节点
var reverse = function(a, b) {
  let pre = null;
  let cur = a;
  while (cur != b) {
    let next = cur.next;
    cur.next = pre;
    pre = cur;
    cur = next;
  }
  return [pre, a];
};
