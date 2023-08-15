def ljust(str, width):
  """在左边填充空格。

  Args:
    str: 要对齐的字符串。
    width: 字符串的宽度。

  Returns:
    对齐后的字符串。
  """
  return str + ' ' * (width - len(str))

def rjust(str, width):
  """在右边填充空格。

  Args:
    str: 要对齐的字符串。
    width: 字符串的宽度。

  Returns:
    对齐后的字符串。
  """
  return ' ' * (width - len(str)) + str

def center(str, width):
  """居中对齐。

  Args:
    str: 要对齐的字符串。
    width: 字符串的宽度。

  Returns:
    对齐后的字符串。
  """
  return ljust(str, width // 2) + ' ' * (width - len(str) - width // 2)

if __name__ == '__main__':
  str = 'Hello, world!'
  width = 10

  print(ljust(str, width))  # 'Hello, world! '
  print(rjust(str, width))  # '   Hello, world!'
  print(center(str, width))  # 'Hello, world!   '
