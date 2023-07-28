int reverse(int x) {
    int res = 0; // 存储反转后的结果
    while (x != 0) { // 当x不为0时循环
        res = res * 10 + x % 10; // 将x的最低位加到res的末尾
        x = x / 10; // 去掉x的最低位
    }
    return res; // 返回反转后的结果
}
