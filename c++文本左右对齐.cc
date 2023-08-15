#include <iostream>
#include <string>

using namespace std;

// 在左边填充空格
string ljust(const string& str, int width) {
  string result = str;
  int padding = width - result.length();
  for (int i = 0; i < padding; i++) {
    result = ' ' + result;
  }
  return result;
}

// 在右边填充空格
string rjust(const string& str, int width) {
  string result = str;
  int padding = width - result.length();
  for (int i = 0; i < padding; i++) {
    result += ' ';
  }
  return result;
}

// 居中对齐
string center(const string& str, int width) {
  string result = ljust(str, width / 2);
  result += rjust("", width - result.length());
  return result;
}

int main() {
  string str = "Hello, world!";
  int width = 10;

  cout << ljust(str, width) << endl;
  cout << rjust(str, width) << endl;
  cout << center(str, width) << endl;

  return 0;
}
