#include <iostream>
#include <vector>

using namespace std;

// 数独板
vector<vector<int>> board = {
  {5, 3, 4, 6, 7, 8, 9, 1, 2},
  {6, 7, 2, 1, 9, 5, 3, 4, 8},
  {1, 9, 8, 7, 2, 3, 5, 6, 4},
  {8, 5, 9, 4, 6, 1, 2, 7, 3},
  {4, 2, 6, 3, 8, 7, 1, 5, 9},
  {7, 1, 3, 9, 5, 2, 6, 8, 0},
  {9, 6, 1, 2, 3, 0, 4, 0, 0},
  {2, 8, 7, 0, 0, 4, 0, 0, 0},
  {3, 4, 0, 0, 0, 6, 7, 9, 5}
};

// 检查数字是否在行、列或 3x3 宫中是否可用
bool is_available(int row, int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) {
      return false;
    }
  }

  for (int i = 0; i < 9; i++) {
    if (board[i][col] == num) {
      return false;
    }
  }

  int start_row = (row / 3) * 3;
  int start_col = (col / 3) * 3;

  for (int i = start_row; i < start_row + 3; i++) {
    for (int j = start_col; j < start_col + 3; j++) {
      if (board[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

// 尝试解决数独
bool solve_sudoku() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == 0) {
        for (int num = 1; num <= 9; num++) {
          if (is_available(row, col, num)) {
            board[row][col] = num;

            if (solve_sudoku()) {
              return true;
            }

            board[row][col] = 0;
          }
        }

        return false;
      }
    }
  }

  return true;
}

// 打印数独板
void print_board() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      cout << board[row][col] << " ";
    }
    cout << endl;
  }
}

int main() {
  if (solve_sudoku()) {
    print_board();
  } else {
    cout << "数独无解" << endl;
  }

  return 0;
}
