package main

import (
	"fmt"
	"math"
)

// minWindow 返回s中包含t所有字符的最小子串
func minWindow(s string, t string) string {
	// need记录t中每个字符出现的次数
	need := make(map[byte]int)
	for i := range t {
		need[t[i]]++
	}
	// left和right是滑动窗口的左右边界
	left, right := 0, 0
	// valid记录窗口中满足need条件的字符个数
	valid := 0
	// start和len记录最小覆盖子串的起始位置和长度
	start, length := 0, math.MaxInt32
	for right < len(s) {
		// c是将要移入窗口的字符
		c := s[right]
		right++
		// 如果c是t中的字符，更新窗口中的数据
		if need[c] > 0 {
			need[c]--
			if need[c] == 0 {
				valid++
			}
		}
		// 判断左侧窗口是否要收缩
		for valid == len(need) {
			// 更新最小覆盖子串
			if right-left < length {
				start = left
				length = right - left
			}
			// d是将要移出窗口的字符
			d := s[left]
			left++
			// 如果d是t中的字符，更新窗口中的数据
			if need[d] >= 0 {
				if need[d] == 0 {
					valid--
				}
				need[d]++
			}
		}
	}
	if length == math.MaxInt32 {
		return ""
	}
	return s[start : start+length]
}

func main() {
	s := "ADOBECODEBANC"
	t := "ABC"
	fmt.Println(minWindow(s, t)) // 输出"BANC"
}
