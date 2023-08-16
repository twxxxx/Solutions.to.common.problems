function minWindow($haystack, $needle) {
  $m = strlen($haystack);
  $n = strlen($needle);
  if ($m < $n) {
    return "";
  }

  // 构造一个哈希表，记录t中每个字符出现的次数
  $need = array_count_values($needle);

  // 构造一个滑动窗口，记录s中当前窗口中每个字符出现的次数
  $have = array_fill(0, 256, 0);
  $left = 0;
  $right = 0;
  $minLen = $m + 1;
  $minStart = -1;

  for ($right = 0; $right < $m; $right++) {
    $have[$haystack[$right]]++;

    // 如果窗口中包含了t中所有的字符，则开始收缩窗口
    while (array_diff_key($have, $need) === array()) {
      if ($right - $left + 1 < $minLen) {
        $minLen = $right - $left + 1;
        $minStart = $left;
      }

      $have[$haystack[$left]]--;
      if ($have[$haystack[$left]] === 0) {
        unset($have[$haystack[$left]]);
      }
      $left++;
    }
  }

  if ($minStart === -1) {
    return "";
  } else {
    return substr($haystack, $minStart, $minLen);
  }
}
