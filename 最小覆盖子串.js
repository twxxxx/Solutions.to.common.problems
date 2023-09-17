// minWindow 返回s中包含t所有字符的最小子串
function minWindow(s, t) {
  // need记录t中每个字符出现的次数
  let need = new Map();
  for (let c of t) {
    need.set(c, need.has(c) ? need.get(c) + 1 : 1);
  }
  // left和right是滑动窗口的左右边界
  let left = 0, right = 0;
  // valid记录窗口中满足need条件的字符个数
  let valid = 0;
  // start和len记录最小覆盖子串的起始位置和长度
  let start = 0, len = Infinity;
  while (right < s.length) {
    // c是将要移入窗口的字符
    let c = s[right];
    // 扩大窗口
    right++;
    // 如果c是t中的字符，更新窗口中的数据
    if (need.has(c)) {
      need.set(c, need.get(c) - 1);
      if (need.get(c) == 0) valid++;
    }
    // 判断左侧窗口是否要收缩
    while (valid == need.size) {
      // 更新最小覆盖子串
      if (right - left < len) {
        start = left;
        len = right - left;
      }
      // d是将要移出窗口的字符
      let d = s[left];
      // 缩小窗口
      left++;
      // 如果d是t中的字符，更新窗口中的数据
      if (need.has(d)) {
        if (need.get(d) == 0) valid--;
        need.set(d, need.get(d) + 1);
      }
    }
  }
  // 返回最小覆盖子串
  return len == Infinity ? "" : s.substring(start, start + len);
}
