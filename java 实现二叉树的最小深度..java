// 定义二叉树的结点类
class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int x) {
    val = x;
    left = null;
    right = null;
  }
}

// 定义一个类，包含一个方法，计算二叉树的最小深度
class Solution {
  public int minDepth(TreeNode root) {
    // 如果根结点为空，返回0
    if (root == null) return 0;
    // 如果左子树为空，返回右子树的最小深度加1
    if (root.left == null) return minDepth(root.right) + 1;
    // 如果右子树为空，返回左子树的最小深度加1
    if (root.right == null) return minDepth(root.left) + 1;
    // 如果左右子树都不为空，返回两者中较小的最小深度加1
    return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
  }
}
