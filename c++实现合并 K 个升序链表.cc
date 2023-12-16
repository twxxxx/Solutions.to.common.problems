#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  if (lists.empty()) {
    return nullptr;
  }

  // 使用优先队列来存储所有链表的头结点，优先队列是按照节点的值进行排序的
  priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> pq;
  for (ListNode* list : lists) {
    if (list != nullptr) {
      pq.push(list);
    }
  }

  // 定义一个头结点，用于存储合并后的链表
  ListNode* head = new ListNode(-1);
  ListNode* cur = head;

  while (!pq.empty()) {
    ListNode* node = pq.top();
    pq.pop();

    // 将节点的值添加到合并后的链表中
    cur->next = node;
    cur = cur->next;

    // 如果节点有下一个节点，则将下一个节点添加到优先队列中
    if (node->next != nullptr) {
      pq.push(node->next);
    }
  }

  // 返回合并后的链表的头结点
  return head->next;
}
