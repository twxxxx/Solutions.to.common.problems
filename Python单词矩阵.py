# 定义字符矩阵
board = [
  ['A', 'B', 'C', 'D'],
  ['E', 'F', 'G', 'H'],
  ['I', 'J', 'K', 'L'],
  ['M', 'N', 'O', 'P']
]

# 输出矩阵
for i in range(len(board)):
  for j in range(len(board[i])):
    print(board[i][j], end=" ")
  print()

# 让用户输入一个单词
word = input("请输入一个单词：")

# 检查单词是否存在于矩阵中
found = False
for i in range(len(board)):
  for j in range(len(board[i])):
    if board[i][j] == word[0]:
      # 找到单词的第一个字母
      for k in range(1, len(word)):
        if i + k < len(board) and board[i + k][j] == word[k]:
          found = True
        elif j + k < len(board[i]) and board[i][j + k] == word[k]:
          found = True
        elif i - k >= 0 and board[i - k][j] == word[k]:
          found = True
        elif j - k >= 0 and board[i][j - k] == word[k]:
          found = True
        else:
          found = False
          break
      if found:
        break
  if found:
    break

# 输出结果
if found:
  print("找到单词", word)
else:
  print("没有找到单词", word)
