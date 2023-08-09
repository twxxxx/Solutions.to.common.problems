<?php

function difference_of_product_and_sum($n) {
  $sum = 0;
  $product = 1;
  while ($n > 0) {
    $digit = $n % 10;
    $sum += $digit;
    $product *= $digit;
    $n /= 10;
  }
  return $product - $sum;
}

$n = 1234;
$result = difference_of_product_and_sum($n);
echo "各位积和之差为：$result";
