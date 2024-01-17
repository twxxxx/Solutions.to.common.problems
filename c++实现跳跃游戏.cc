class Solution {
    bool backTracking(vector<int>& nums, int i) {
        if (i + nums[i] >= static_cast<int>(nums.size()) - 1) return true; // static_cast<int> - 因为需要用unsigned - 1，转换成int比较保险，否则0 - 1会溢出
        // if (!nums[i]) return false; // 添加这句可以通过test case1，但是另一个不行
        for (int j = nums[i]; j > 0; j--) if (backTracking(nums, j + i)) return true;
        return false;
    }

public:
    bool canJump(vector<int>& nums) { return backTracking(nums, 0); }
};
