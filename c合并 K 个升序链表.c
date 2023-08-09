#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct ListNode {
  int val;
  struct ListNode *next;
};

// 合并两个链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* head = NULL;
  struct ListNode* tail = NULL;

  while (l1 != NULL && l2 != NULL) {
    if (l1->val < l2->val) {
      if (head == NULL) {
        head = l1;
        tail = l1;
      } else {
        tail->next = l1;
        tail = tail->next;
      }
      l1 = l1->next;
    } else {
      if (head == NULL) {
        head = l2;
        tail = l2;
      } else {
        tail->next = l2;
        tail = tail->next;
      }
      l2 = l2->next;
    }
  }

  if (l1 != NULL) {
    tail->next = l1;
  }

  if (l2 != NULL) {
    tail->next = l2;
  }

  return head;
}

// 合并K个链表
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
  if (k == 0) {
    return NULL;
  }

  struct ListNode* head = lists[0];
  for (int i = 1; i < k; i++) {
    head = mergeTwoLists(head, lists[i]);
  }

  return head;
}

// 测试代码
int main() {
  struct ListNode* l1 = NULL;
  l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
  l1->val = 1;
  l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l1->next->val = 3;
  l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l1->next->next->val = 5;

  struct ListNode* l2 = NULL;
  l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
  l2->val = 2;
  l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l2->next->val = 4;
  l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l2->next->next->val = 6;

  struct ListNode* l3 = NULL;
  l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
  l3->val = 7;
  l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l3->next->val = 8;
  l3->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l3->next->next->val = 9;

  struct ListNode** lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * 3);
  lists[0] = l1;
  lists[1] = l2;
  lists[2] = l3;

  int k = 3;

  struct ListNode* head = mergeKLists(lists, k);

  while (head != NULL) {
    printf("%d ", head->val);
    head = head->next;
  }

  printf("\n");

  return 0;
}
