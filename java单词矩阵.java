import java.util.Scanner;

public class WordSearch {

    public static void main(String[] args) {
        // 定义字符矩阵
        char board[][] = {
            {'A', 'B', 'C', 'D'},
            {'E', 'F', 'G', 'H'},
            {'I', 'J', 'K', 'L'},
            {'M', 'N', 'O', 'P'}
        };

        // 输出矩阵
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }

        // 让用户输入一个单词
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入一个单词：");
        String word = scanner.next();

        // 检查单词是否存在于矩阵中
        boolean found = false;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    // 找到单词的第一个字母
                    for (int k = 1; k < word.length(); k++) {
                        if (i + k < board.length && board[i + k][j] == word.charAt(k)) {
                            found = true;
                        } else if (j + k < board[0].length && board[i][j + k] == word.charAt(k)) {
                            found = true;
                        } else if (i - k >= 0 && board[i - k][j] == word.charAt(k)) {
                            found = true;
                        } else if (j - k >= 0 && board[i][j - k] == word.charAt(k)) {
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
            System.out.println("找到单词" + word);
        } else {
            System.out.println("没有找到单词" + word);
        }
    }
}
