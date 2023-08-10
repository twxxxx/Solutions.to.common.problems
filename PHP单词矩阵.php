<?php

// 定义字符矩阵
$board = [
  ['A', 'B', 'C', 'D'],
  ['E', 'F', 'G', 'H'],
  ['I', 'J', 'K', 'L'],
  ['M', 'N', 'O', 'P']
];

// 输出矩阵
foreach ($board as $row) {
  foreach ($row as $col) {
    echo $col . " ";
  }
  echo "<br>";
}

// 让用户输入一个单词
$word = readline("请输入一个单词：");

// 检查单词是否存在于矩阵中
$found = false;
for ($i = 0; $i < count($board); $i++) {
  for ($j = 0; $j < count($board[$i]); $j++) {
    if ($board[$i][$j] == $word[0]) {
      // 找到单词的第一个字母
      for ($k = 1; $k < strlen($word); $k++) {
        if ($i + $k < count($board) && $board[$i + $k][$j] == $word[$k]) {
          $found = true;
        } else if ($j + $k < count($board[$i]) && $board[$i][$j + $k] == $word[$k]) {
          $found = true;
        } else if ($i - $k >= 0 && $board[$i - $k][$j] == $word[$k]) {
          $found = true;
        } else if ($j - $k >= 0 && $board[$i][$j - $k] == $word[$k]) {
          $found = true;
        } else {
          $found = false;
          break;
        }
      }
      if ($found) {
        break;
      }
    }
  }
  if ($found) {
    break;
  }
}

// 输出结果
if ($found) {
  echo "找到单词 $word";
} else {
  echo "没有找到单词 $word";
}

?>
