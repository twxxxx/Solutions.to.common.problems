def difference_of_product_and_sum(n):
  """
  计算整数各位积和之差。

  Args:
    n: 整数。

  Returns:
    整数各位积和之差。
  """
  sum = 0
  product = 1
  while n > 0:
    digit = n % 10
    sum += digit
    product *= digit
    n //= 10
  return product - sum
