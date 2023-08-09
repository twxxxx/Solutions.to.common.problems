def mergeTwoLists(l1, l2):
  if l1 is None:
    return l2
  if l2 is None:
    return l1

  result = None
  while l1 is not None and l2 is not None:
    if l1.val < l2.val:
      result = l1
      l1 = l1.next
    else:
      result = l2
      l2 = l2.next

  result.next = l1 if l1 is not None else l2
  return result

def mergeKLists(lists):
  if len(lists) == 0:
    return None

  result = lists[0]
  for i in range(1, len(lists)):
    result = mergeTwoLists(result, lists[i])

  return result

# 测试代码
list1 = [1, 3, 5]
list2 = [2, 4, 6]
list3 = [7, 8, 9]

lists = [list1, list2, list3]

result = mergeKLists(lists)

while result is not None:
  print(result.val)
  result = result.next
