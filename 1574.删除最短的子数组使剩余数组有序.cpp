/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

// @lc code=start
class Solution {
public:
  int findLengthOfShortestSubarray(vector<int> &arr) {
    int n = arr.size();
    int right = n - 1;
    // 从右往左找到第一个不满足升序的位置
    while (right && arr[right] >= arr[right - 1]) {
      --right;
    }
    // 如果整个数组都是升序的，那么直接返回 0
    if (right == 0) {
      return 0;
    }
    int res = right;
    // 从左往右找到第一个不满足升序的位置
    for (int left = 0; left == 0 || arr[left - 1] <= arr[left]; ++left) {
      // 如果 left 指向的元素大于 right 指向的元素，那么就不是升序
      // 需要将 right 后移保持升序，那么 left 到 right 之间的元素就是需要删除的
      while (right < n && arr[left] > arr[right]) {
        ++right;
      }
      res = min(res, right - left - 1);
    }
    return res;
  }
};
// @lc code=end
