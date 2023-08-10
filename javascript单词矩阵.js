// 定义字符矩阵
const board = [
  ['A', 'B', 'C', 'D'],
  ['E', 'F', 'G', 'H'],
  ['I', 'J', 'K', 'L'],
  ['M', 'N', 'O', 'P']
];

// 输出矩阵
for (let i = 0; i < board.length; i++) {
  for (let j = 0; j < board[i].length; j++) {
    console.log(board[i][j] + " ");
  }
  console.log();
}

// 让用户输入一个单词
let word = prompt("请输入一个单词：");

// 检查单词是否存在于矩阵中
let found = false;
for (let i = 0; i < board.length; i++) {
  for (let j = 0; j < board[i].length; j++) {
    if (board[i][j] === word[0]) {
      // 找到单词的第一个字母
      for (let k = 1; k < word.length; k++) {
        if (i + k < board.length && board[i + k][j] === word[k]) {
          found = true;
        } else if (j + k < board[i].length && board[i][j + k] === word[k]) {
          found = true;
        } else if (i - k >= 0 && board[i - k][j] === word[k]) {
          found = true;
        } else if (j - k >= 0 && board[i][j - k] === word[k]) {
          found = true;
        } else {
          found = false;
          break;
        }
      }
      if (found) {
        break;
      }
    }
  }
  if (found) {
    break;
  }
}

// 输出结果
if (found) {
  console.log("找到单词" + word);
} else {
  console.log("没有找到单词" + word);
}
