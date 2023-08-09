package main

import (
    "fmt"
)

func main() {
    var n int
    fmt.Println("请输入一个正整数：")
    fmt.Scanf("%d", &n)

    sum := 0
    product := 1
    for n > 0 {
        digit := n % 10
        sum += digit
        product *= digit
        n /= 10
    }

    fmt.Println("各位积和之差为：", product - sum)
}
