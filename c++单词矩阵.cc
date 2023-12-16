#include <iostream>
#include <string>

using namespace std;

int main() {
  // 初始化矩阵
  string board[4][4] = {
    {"A", "B", "C", "D"},
    {"E", "F", "G", "H"},
    {"I", "J", "K", "L"},
    {"M", "N", "O", "P"}
  };

  // 输出矩阵
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  // 让用户输入一个单词
  string word;
  cout << "请输入一个单词：";
  cin >> word;

  // 检查单词是否存在于矩阵中
  bool found = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == word[0]) {
        // 找到单词的第一个字母
        for (int k = 1; k < word.length(); k++) {
          if (i + k < 4 && board[i + k][j] == word[k]) {
            found = true;
          } else if (j + k < 4 && board[i][j + k] == word[k]) {
            found = true;
          } else if (i - k >= 0 && board[i - k][j] == word[k]) {
            found = true;
          } else if (j - k >= 0 && board[i][j - k] == word[k]) {
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
    cout << "找到单词" << word << endl;
  } else {
    cout << "没有找到单词" << word << endl;
  }

  return 0;
}
