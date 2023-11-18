package main

import (
	"fmt"
	"strconv"
)

// 定义运算符号的优先级关系
var precedence = map[string]int{
	"+": 1,
	"-": 1,
	"*": 2,
	"/": 2,
	"%": 2,
	"(": 0,
	")": 0,
}

// 比较两个运算符号的优先级，返回-1表示低于，0表示等于，1表示高于
func compare(op1, op2 string) int {
	if precedence[op1] < precedence[op2] {
		return -1
	} else if precedence[op1] == precedence[op2] {
		return 0
	} else {
		return 1
	}
}

// 根据运算符号对两个操作数进行计算
func calculate(num1, num2 int, op string) int {
	switch op {
	case "+":
		return num1 + num2
	case "-":
		return num1 - num2
	case "*":
		return num1 * num2
	case "/":
		return num1 / num2
	case "%":
		return num1 % num2
	default:
		return 0
	}
}

// 将中缀表达式转换为后缀表达式
func infixToPostfix(infix string) string {
	opStack := []string{} // 存储运算符的栈
	postfix := []string{} // 存储后缀表达式的切片
	for _, c := range infix { // 遍历中缀表达式的每个字符
		if c >= '0' && c <= '9' { // 如果是数字，直接添加到后缀表达式中
			postfix = append(postfix, string(c))
		} else if c == '(' { // 如果是左括号，压入栈中
			opStack = append(opStack, string(c))
		} else if c == ')' { // 如果是右括号，弹出栈中的运算符，直到遇到左括号
			for len(opStack) > 0 && opStack[len(opStack)-1] != "(" {
				postfix = append(postfix, opStack[len(opStack)-1])
				opStack = opStack[:len(opStack)-1]
			}
			if len(opStack) > 0 && opStack[len(opStack)-1] == "(" {
				opStack = opStack[:len(opStack)-1] // 弹出左括号
			}
		} else { // 如果是运算符，比较它和栈顶运算符的优先级
			for len(opStack) > 0 && compare(string(c), opStack[len(opStack)-1]) <= 0 {
				// 如果栈顶运算符的优先级高于或等于它，弹出栈顶运算符并添加到后缀表达式中
				postfix = append(postfix, opStack[len(opStack)-1])
				opStack = opStack[:len(opStack)-1]
			}
			// 将它压入栈中
			opStack = append(opStack, string(c))
		}
	}
	// 将栈中剩余的运算符依次弹出并添加到后缀表达式中
	for len(opStack) > 0 {
		postfix = append(postfix, opStack[len(opStack)-1])
		opStack = opStack[:len(opStack)-1]
	}
	// 将后缀表达式的切片转换为字符串
	return fmt.Sprint(postfix)
}

// 计算后缀表达式的值
func evaluatePostfix(postfix string) int {
	numStack := []int{} // 存储操作数的栈
	for _, c := range postfix { // 遍历后缀表达式的每个字符
		if c >= '0' && c <= '9' { // 如果是数字，压入栈中
			num, _ := strconv.Atoi(string(c))
			numStack = append(numStack, num)
		} else { // 如果是运算符，弹出栈中的两个操作数，用该运算符对它们进行计算，然后将结果压入栈中
			num2 := numStack[len(numStack)-1]
			numStack = numStack[:len(numStack)-1]
			num1 := numStack[len(numStack)-1]
			numStack = numStack[:len(numStack)-1]
			result := calculate(num1, num2, string(c))
			numStack = append(numStack, result)
		}
	}
	// 栈中剩余的一个元素就是后缀表达式的值
	return numStack[0]
}

func main() {
	infix := "2*(3+4)-5/2" // 中缀表达式
	postfix := infixToPostfix(infix) // 后缀表达式
	value := evaluatePostfix(postfix) // 后缀表达式的值
	fmt.Println("中缀表达式: ", infix)
	fmt.Println("后缀表达式: ", postfix
