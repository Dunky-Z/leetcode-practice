/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
public:
    unordered_map<int, int> value_index;
    vector<int> nums;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (value_index.count(val))
            return false;
        value_index[val] = value_index.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (value_index.count(val) == 0)
        {
            return false;
        }
        auto index = value_index[val];
        value_index[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        value_index.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
