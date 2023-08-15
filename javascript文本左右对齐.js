function ljust(str, width) {
  return str + Array(width - str.length + 1).join(' ');
}

function rjust(str, width) {
  return Array(width - str.length + 1).join(' ') + str;
}

function center(str, width) {
  return ljust(str, width / 2) + Array(width - str.length).join(' ');
}

// 测试用例
console.log(ljust('Hello, world!', 10)); // 'Hello, world! '
console.log(rjust('Hello, world!', 10)); // '   Hello, world!'
console.log(center('Hello, world!', 10)); // 'Hello, world!   '
