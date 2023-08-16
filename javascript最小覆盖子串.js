function minWindow(s, t) {
  let m = s.length;
  let n = t.length;
  if (m < n) {
    return "";
  }

  // 构造一个哈希表，记录t中每个字符出现的次数
  let need = new Map();
  for (let i = 0; i < n; i++) {
    need.set(t[i], need.get(t[i]) || 0) + 1;
  }

  // 构造一个滑动窗口，记录s中当前窗口中每个字符出现的次数
  let have = new Map();
  let left = 0;
  let right = 0;
  let minLen = m + 1;
  let minStart = -1;

  for (right = 0; right < m; right++) {
    have.set(s[right], have.get(s[right]) || 0) + 1;

    // 如果窗口中包含了t中所有的字符，则开始收缩窗口
    while (need.every(([key, value]) => have.get(key) >= value)) {
      if (right - left + 1 < minLen) {
        minLen = right - left + 1;
        minStart = left;
      }

      have.set(s[left], have.get(s[left]) - 1);
      if (have.get(s[left]) === 0) {
        have.delete(s[left]);
      }
      left++;
    }
  }

  if (minStart === -1) {
    return "";
  } else {
    return s.slice(minStart, minStart + minLen);
  }
}
