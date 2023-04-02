/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {}
};
// @lc code=end
// 给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2，每个数组中的元素
// 互不相同，请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。
class Solution {
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2) {
    //   思路：将 nums1 中的所有元素放入一个 unordered_set 中。然后遍历 nums2
    //   中的所有元素，如果该元素在 nums1 中也存在，判断是否是最小的。
    //   如果是最小的，直接返回该元素。如果不是最小的，继续遍历 nums2
    //   中的下一个元素。

    unordered_set<int> s(nums1.begin(), nums1.end());
    int ans = INT_MAX;
    for (int num : nums2) {
      if (s.count(num)) {
        ans = min(ans, num);
      }
    }
    if (ans != INT_MAX) {
      return ans;
    }
    //   如果 nums2 中的所有元素都不在 nums1 中，那么返回 nums1 和 nums2
    //   能够组合成的最小的两位数。找出 num1 和 nums2 中最小的元素，然后将它们
    //  拼接起来，就是最小的两位数。
    return min(*min_element(nums1.begin(), nums1.end()),
               *min_element(nums2.begin(), nums2.end())) *
               10 +
           max(*min_element(nums1.begin(), nums1.end()),
               *min_element(nums2.begin(), nums2.end()));
  }
};

class Solution {
public:
  int maximumCostSubstring(string s, string chars, vector<int> &vals) {
    // 遍历字符串 s 的所有子串，每次计算其开销并记录最大开销
    unordered_map<char, int> val_map;
    int n = s.size();
    int res = 0;
    // 使用一个哈希表来保存每个字符对应的价值
    for (int i = 0; i < chars.size(); i++) {
      val_map[chars[i]] = vals[i];
    }
    // 对于每个子串遍历其中的所有字符，累加其价值并更新最大价值
    for (int i = 0; i < n; i++) {
      int cur_val = 0, cur_max_val = INT_MIN;
      for (int j = i; j < n; j++) {
        if (val_map.count(s[j])) {
          cur_val += val_map[s[j]];
        } else {
          cur_val += s[j] - 'a' + 1;
        }
        cur_max_val = max(cur_max_val, cur_val);
      }
      res = max(res, cur_max_val);
    }
    return res;
  }
};

下面是使用双指针优化的代码：
class Solution {
public:
  int maximumCostSubstring(string s, string chars, vector<int> &vals) {
    unordered_map<char, int> val_map;
    int n = s.size();
    int left = 0, right = 0;
    int cur_val = 0, cur_max_val = INT_MIN;
    int res = 0;
    for (int i = 0; i < chars.size(); i++) {
      val_map[chars[i]] = vals[i];
    }
    while (right < n) {
      if (val_map.count(s[right])) {
        cur_val += val_map[s[right]];
      } else {
        cur_val += s[right] - 'a' + 1;
      }
      right++;
      while (left < right && !check(val_map, s.substr(left, right - left))) {
        if (val_map.count(s[left])) {
          cur_val -= val_map[s[left]];
        } else {
          cur_val -= s[left] - 'a' + 1;
        }
        left++;
      }
      cur_max_val = max(cur_max_val, cur_val);
      res = max(res, cur_max_val);
    }
    return res;
  }
  bool check(unordered_map<char, int> &val_map, string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
      if (val_map.count(c)) {
        freq[c]++;
      }
    }
    for (auto p : val_map) {
      if (freq[p.first] < p.second) {
        return false;
      }
    }
    return true;
  }
};

在这个代码中，我们使用了一个辅助函数
check 来判断当前子串是否包含了 chars 中的所有字符。该函数的时间复杂度为
O(k)，其中 k 是 chars 的长度。因此，总时间复杂度为
    O(nk)。但是，在实际情况下，k 通常比较小，因此该算法的时间复杂度可以近似看作
    O(n)。

class Solution {
public:
  long long makeSubKSumEqual(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> diff(n);
    for (int i = 0; i < n - 1; i++) {
      diff[i] = arr[i + 1] - arr[i];
    }
    diff[n - 1] = arr[0] - arr[n - 1];
    long long ans = LONG_LONG_MAX;
    for (int i = 0; i < k; i++) {
      int cnt = 0;
      for (int j = i; j < n; j += k) {
        cnt += diff[j];
      }
      ans = min(ans, abs(cnt));
      ans = min(ans, k - abs(cnt % k));
    }
    return ans;
  }
};