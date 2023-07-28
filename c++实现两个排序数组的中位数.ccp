#include <iostream>
#include <vector>

using namespace std;

// 这是一个函数，它接受两个排序数组并返回它们的中位数。
int medianOfTwoSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  // 检查两个数组是否为空。
  if (nums1.empty() || nums2.empty()) {
    return -1;
  }

  // 获取两个数组的长度。
  int m = nums1.size();
  int n = nums2.size();

  // 创建一个新的数组，用于存储两个数组的中间元素。
  vector<int> mergedArray(m + n);

  // 将两个数组的中间元素合并到新数组中。
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < m && j < n) {
    if (nums1[i] <= nums2[j]) {
      mergedArray[k++] = nums1[i++];
    } else {
      mergedArray[k++] = nums2[j++];
    }
  }

  // 将剩余的元素从第一个数组复制到新数组中。
  while (i < m) {
    mergedArray[k++] = nums1[i++];
  }

  // 将剩余的元素从第二个数组复制到新数组中。
  while (j < n) {
    mergedArray[k++] = nums2[j++];
  }

  // 获取新数组的中间元素。
  int median = mergedArray[(m + n) / 2];

  // 返回中间元素。
  return median;
}

int main() {
  // 创建两个排序数组。
  vector<int> nums1 = {1, 3, 5, 7, 9};
  vector<int> nums2 = {2, 4, 6, 8, 10};

  // 调用函数并获取中间元素。
  int median = medianOfTwoSortedArrays(nums1, nums2);

  // 打印中间元素。
  cout << "The median of the two sorted arrays is: " << median << endl;

  return 0;
}
