string minWindow(string s, string t) {
  int m = s.length();
  int n = t.length();
  if (m < n) {
    return "";
  }

  // 构造一个哈希表，记录t中每个字符出现的次数。
  unordered_map<char, int> need;
  for (int i = 0; i < n; i++) {
    need[t[i]]++;
  }

  // 构造一个滑动窗口，记录s中当前窗口中每个字符出现的次数。
  unordered_map<char, int> have;
  int left = 0;
  int right = 0;
  int minLen = m + 1;
  int minStart = -1;

  for (right = 0; right < m; right++) {
    have[s[right]]++;

    // 如果窗口中包含了t中所有的字符，则开始收缩窗口。
    while (all_of(need.begin(), need.end(), [&](const auto& p) { return have[p.first] >= p.second; })) {
      if (right - left + 1 < minLen) {
        minLen = right - left + 1;
        minStart = left;
      }

      have[s[left]]--;
      left++;
    }
  }

  if (minStart == -1) {
    return "";
  } else {
    return s.substr(minStart, minLen);
  }
}