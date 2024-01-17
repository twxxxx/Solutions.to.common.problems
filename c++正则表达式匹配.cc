#include <iostream>
#include <regex>
using namespace std;

int main()
{
    // 定义一个正则表达式对象，用来匹配实数
    regex re("^-?(\\d+\\.?\\d*|\\d*\\.?\\d+)(e[+-]?\\d+)?$");

    // 定义一个字符串，用来存储用户的输入
    string str;

    // 从标准输入读取一行字符串
    getline(cin, str);

    // 定义一个匹配结果对象，用来存储匹配的信息
    smatch result;

    // 使用regex_match函数进行全文匹配，如果匹配成功，输出"匹配成功"，否则输出"匹配失败"
    if (regex_match(str, result, re))
    {
        cout << "匹配成功" << endl;
    }
    else
    {
        cout << "匹配失败" << endl;
    }

    // 使用regex_search函数进行搜索匹配，如果匹配成功，输出"查找成功"和匹配的子串，否则输出"查找失败"
    if (regex_search(str, result, re))
    {
        cout << "查找成功：" << result[0] << endl;
    }
    else
    {
        cout << "查找失败" << endl;
    }

    // 使用regex_replace函数进行替换匹配，将字符串中的实数替换为"***"，并输出替换后的字符串
    string new_str = regex_replace(str, re, "***");
    cout << "替换后的字符串：" << new_str << endl;

    return 0;
}
