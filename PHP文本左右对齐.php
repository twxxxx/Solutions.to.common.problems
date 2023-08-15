<?php

// 左对齐
function ljust($str, $width) {
  return str_pad($str, $width, ' ', STR_PAD_LEFT);
}

// 右对齐
function rjust($str, $width) {
  return str_pad($str, $width, ' ', STR_PAD_RIGHT);
}

// 居中对齐
function center($str, $width) {
  return str_pad($str, $width, ' ', STR_PAD_BOTH);
}

// 测试用例
echo ljust('Hello, world!', 10) . PHP_EOL; // 'Hello, world! '
echo rjust('Hello, world!', 10) . PHP_EOL; // '   Hello, world!'
echo center('Hello, world!', 10) . PHP_EOL; // 'Hello, world!   '
