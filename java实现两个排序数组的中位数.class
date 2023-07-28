import java.util.Arrays;

public class MedianOfTwoSortedArrays {

    public static double findMedian(int[] arr1, int[] arr2) {
        int n1 = arr1.length;
        int n2 = arr2.length;

        // 确保 arr1 的长度小于或等于 arr2 的长度
        if (n1 > n2) {
            int[] temp = arr1;
            arr1 = arr2;
            arr2 = temp;
        }

        // 定义两个指针，分别指向 arr1 和 arr2 的起始位置
        int i = 0;
        int j = 0;

        // 定义一个变量，保存中位数
        double median = 0;

        // 循环，直到找到中位数
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                median = arr1[i];
                i++;
            } else {
                median = arr2[j];
                j++;
            }
        }

        // 如果 arr1 还有剩余元素，则中位数为 arr1 的最后一个元素
        if (i < n1) {
            median = arr1[i];
        }

        // 如果 arr2 还有剩余元素，则中位数为 arr2 的最后一个元素
        if (j < n2) {
            median = arr2[j];
        }

        return median;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 3, 5, 7};
        int[] arr2 = {2, 4, 6, 8};

        System.out.println("The median of the two sorted arrays is: " + findMedian(arr1, arr2));
    }
}
