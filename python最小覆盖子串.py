def min_window(s, t):
  """
  给定一个字符串s和一个字符串t，返回s中包含t所有字符的最小子串。

  Args:
    s: 输入字符串。
    t: 目标字符串。

  Returns:
    包含t所有字符的最小子串。如果s中不包含t所有字符，则返回空字符串。
  """
  m = len(s)
  n = len(t)
  if m < n:
    return ""

  # 构造一个哈希表，记录t中每个字符出现的次数。
  need = {}
  for c in t:
    need[c] = need.get(c, 0) + 1

  # 构造一个滑动窗口，记录s中当前窗口中每个字符出现的次数。
  have = {}
  left = 0
  right = 0
  min_len = m + 1
  min_start = -1

  for right in range(m):
    have[s[right]] = have.get(s[right], 0) + 1

    # 如果窗口中包含了t中所有的字符，则开始收缩窗口。
    while all(have.get(c, 0) >= need[c] for c in need):
      if right - left + 1 < min_len:
        min_len = right - left + 1
        min_start = left

      have[s[left]] -= 1
      left += 1

  if min_start == -1:
    return ""
  else:
    return s[min_start:min_start + min_len]
