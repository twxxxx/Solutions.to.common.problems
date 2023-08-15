public class TextAlignment {

    public static void main(String[] args) {
        String str = "Hello, world!";
        int width = 10;

        // 在左边填充空格
        System.out.println(String.format("%-10s", str));

        // 在右边填充空格
        System.out.println(String.format("%10s", str));

        // 居中对齐
        System.out.println(String.format("%-5s%5s", str, ""));
    }
}
