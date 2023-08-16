func minWindow(s string, t string) string {
  m := len(s)
  n := len(t)
  if m < n {
    return ""
  }

  // 构造一个哈希表，记录t中每个字符出现的次数
  need := make(map[rune]int)
  for _, c := range t {
    need[c]++
  }

  // 构造一个滑动窗口，记录s中当前窗口中每个字符出现的次数
  have := make(map[rune]int)
  left := 0
  right := 0
  minLen := m + 1
  minStart := -1

  for right < m {
    c := rune(s[right])
    have[c]++

    // 如果窗口中包含了t中所有的字符，则开始收缩窗口
    for len(need) == len(have) {
      if right - left + 1 < minLen {
        minLen = right - left + 1
        minStart = left
      }

      d := rune(s[left])
      have[d]--

      // 如果窗口中删除了一个字符，则左边界向右移动
      if have[d] == 0 {
        delete(have, d)
      }

      left++
    }

    right++
  }

  if minStart == -1 {
    return ""
  } else {
    return s[minStart:minStart + minLen]
  }
}
