func ljust(str string, width int) string {
  padding := width - len(str)
  return str + strings.Repeat(" ", padding)
}

func rjust(str string, width int) string {
  padding := width - len(str)
  return strings.Repeat(" ", padding) + str
}

func center(str string, width int) string {
  padding := (width - len(str)) / 2
  return strings.Repeat(" ", padding) + str + strings.Repeat(" ", padding)
}

func main() {
  str := "Hello, world!"
  width := 10

  fmt.Println(ljust(str, width))  // Hello, world!
  fmt.Println(rjust(str, width))  //    Hello, world!
  fmt.Println(center(str, width)) // Hello, world!
}
