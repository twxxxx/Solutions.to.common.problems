function mergeTwoLists(l1, l2) {
  if (l1 === null) {
    return l2;
  } else if (l2 === null) {
    return l1;
  }

  let result = null;
  while (l1 !== null && l2 !== null) {
    if (l1.val < l2.val) {
      result = l1;
      l1 = l1.next;
    } else {
      result = l2;
      l2 = l2.next;
    }
  }

  result.next = l1 === null ? l2 : l1;
  return result;
}

function mergeKLists(lists) {
  if (lists.length === 0) {
    return null;
  }

  let result = lists[0];
  for (let i = 1; i < lists.length; i++) {
    result = mergeTwoLists(result, lists[i]);
  }

  return result;
}

// 测试代码
const list1 = [1, 3, 5];
const list2 = [2, 4, 6];
const list3 = [7, 8, 9];

const lists = [list1, list2, list3];

const result = mergeKLists(lists);

while (result !== null) {
  console.log(result.val);
  result = result.next;
}
