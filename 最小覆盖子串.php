<?php
// minWindow 返回s中包含t所有字符的最小子串
function minWindow($s, $t) {
  // need记录t中每个字符出现的次数
  $need = array();
  for ($i = 0; $i < strlen($t); $i++) {
    $c = $t[$i];
    if (isset($need[$c])) {
      $need[$c]++;
    } else {
      $need[$c] = 1;
    }
  }
  // left和right是滑动窗口的左右边界
  $left = 0;
  $right = 0;
  // valid记录窗口中满足need条件的字符个数
  $valid = 0;
  // start和len记录最小覆盖子串的起始位置和长度
  $start = 0;
  $len = PHP_INT_MAX;
  while ($right < strlen($s)) {
    // c是将要移入窗口的字符
    $c = $s[$right];
    // 扩大窗口
    $right++;
    // 如果c是t中的字符，更新窗口中的数据
    if (isset($need[$c])) {
      if (isset($window[$c])) {
        $window[$c]++;
      } else {
        $window[$c] = 1;
      }
      if ($window[$c] == $need[$c]) {
        $valid++;
      }
    }
    // 判断左侧窗口是否要收缩
    while ($valid == count($need)) {
      // 更新最小覆盖子串
      if ($right - $left < $len) {
        $start = $left;
        $len = $right - $left;
      }
      // d是将要移出窗口的字符
      $d = $s[$left];
      // 缩小窗口
      $left++;
      // 如果d是t中的字符，更新窗口中的数据
      if (isset($need[$d])) {
        if ($window[$d] == $need[$d]) {
          $valid--;
        }
        $window[$d]--;
      }
    }
  }
  // 返回最小覆盖子串
  return ($len == PHP_INT_MAX) ? "" : substr($s, $start, $len);
}

$s = "ADOBECODEBANC";
$t = "ABC";
echo minWindow($s, $t); // 输出"BANC"
?>
