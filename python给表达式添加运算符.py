# 定义运算符号的优先级关系，用一个字典表示
precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '%': 2, '**': 3, '(': 0, ')': 0}

# 比较两个运算符号的优先级，返回True表示第一个运算符的优先级高于或等于第二个运算符的优先级
def compare(op1, op2):
    return precedence[op1] >= precedence[op2]

# 根据运算符号对两个操作数进行计算
def calculate(num1, num2, op):
    if op == '+':
        return num1 + num2
    elif op == '-':
        return num1 - num2
    elif op == '*':
        return num1 * num2
    elif op == '/':
        return num1 / num2
    elif op == '%':
        return num1 % num2
    elif op == '**':
        return num1 ** num2
    else:
        return 0

# 将中缀表达式转换为后缀表达式
def infix_to_postfix(infix):
    op_stack = [] # 存储运算符的栈
    postfix = [] # 存储后缀表达式的列表
    for c in infix: # 遍历中缀表达式的每个字符
        if c.isdigit():
