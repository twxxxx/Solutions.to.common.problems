package main

import (
    "fmt"
    "strings"
)

func main() {
    // 定义字符矩阵
    board := [][]string{
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"},
        {"I", "J", "K", "L"},
        {"M", "N", "O", "P"},
    }

    // 输出矩阵
    for _, row := range board {
        for _, col := range row {
            fmt.Print(col, " ")
        }
        fmt.Println()
    }

    // 让用户输入一个单词
    word := strings.TrimSpace(fmt.Sprintf("请输入一个单词: "))

    // 检查单词是否存在于矩阵中
    found := false
    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[i]); j++ {
            if board[i][j] == word[0] {
                // 找到单词的第一个字母
                for k := 1; k < len(word); k++ {
                    if i + k < len(board) && board[i + k][j] == word[k] {
                        found = true
                    } else if j + k < len(board[i]) && board[i][j + k] == word[k] {
                        found = true
                    } else if i - k >= 0 && board[i - k][j] == word[k] {
                        found = true
                    } else if j - k >= 0 && board[i][j - k] == word[k] {
                        found = true
                    } else {
                        found = false
                        break
                    }
                }
                if found {
                    break
                }
            }
        }
        if found {
            break
        }
    }

    // 输出结果
    if found {
        fmt.Println("找到单词", word)
    } else {
        fmt.Println("没有找到单词", word)
    }
}
