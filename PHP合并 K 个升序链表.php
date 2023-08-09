<?php

// 定义链表节点
class ListNode {
  public $val;
  public $next;

  public function __construct($val) {
    $this->val = $val;
    $this->next = null;
  }
}

// 合并两个链表
function mergeTwoLists(ListNode $l1, ListNode $l2) {
  if ($l1 === null) {
    return $l2;
  }
  if ($l2 === null) {
    return $l1;
  }

  if ($l1->val < $l2->val) {
    $l1->next = mergeTwoLists($l1->next, $l2);
    return $l1;
  } else {
    $l2->next = mergeTwoLists($l1, $l2->next);
    return $l2;
  }
}

// 合并K个链表
function mergeKLists(array $lists) {
  if (count($lists) === 0) {
    return null;
  }

  $head = new ListNode(PHP_INT_MIN);
  $current = $head;

  foreach ($lists as $list) {
    while ($list !== null) {
      $current->next = mergeTwoLists($current->next, $list);
      $current = $current->next;
      $list = $list->next;
    }
  }

  return $head->next;
}

// 测试代码
$list1 = new ListNode(1);
$list1->next = new ListNode(3);
$list1->next->next = new ListNode(5);

$list2 = new ListNode(2);
$list2->next = new ListNode(4);
$list2->next->next = new ListNode(6);

$list3 = new ListNode(7);
$list3->next = new ListNode(8);
$list3->next->next = new ListNode(9);

$lists = [$list1, $list2, $list3];

$head = mergeKLists($lists);

while ($head !== null) {
  echo $head->val, ' ';
  $head = $head->next;
}
