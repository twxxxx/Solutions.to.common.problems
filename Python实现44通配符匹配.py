def wild_match(pattern, text):
  """
  匹配模式和文本，支持 * 和 ? 通配符。

  Args:
    pattern: 模式字符串。
    text: 文本字符串。

  Returns:
    如果匹配成功，返回 True。如果匹配失败，返回 False。
  """
  if pattern == text:
    return True

  if pattern[0] == '*':
    return wild_match(pattern[1:], text) or wild_match(pattern[1:], text[1:])
  elif pattern[0] == '?':
    return wild_match(pattern[1:], text[1:])
  else:
    return pattern[0] == text[0] and wild_match(pattern[1:], text[1:])


if __name__ == "__main__":
  print(wild_match("*", "abc"))  # True
  print(wild_match("*", "a"))  # True
  print(wild_match("a*", "abc"))  # True
  print(wild_match("a*c", "abc"))  # True
  print(wild_match("a*c", "abcd"))  # False
  print(wild_match("*c", "abc"))  # True
  print(wild_match("*c", "abcd"))  # True
  print(wild_match("?bc", "abc"))  # True
  print(wild_match("?bc", "abcd"))  # True
