/*
 * @lc app=leetcode.cn id=2409 lang=cpp
 *
 * [2409] 统计共同度过的日子数
 */

// @lc code=start
class Solution {
public:
    vector<int> datesOfMonths = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> prefixSum = {0};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        for (int date : datesOfMonths) {
            prefixSum.emplace_back(prefixSum.back() + date);
        }
        int arriveAliceDay = countDayOfYear(arriveAlice);
        int leaveAliceDay = countDayOfYear(leaveAlice);
        int arriveBobDay = countDayOfYear(arriveBob);
        int leaveBobDay = countDayOfYear(leaveBob);
        if(arriveAliceDay > leaveBobDay || arriveBobDay > leaveAliceDay)
            return 0;
        return min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;
    }
    // 计算某一天是该年的第几天，08-01 是第 213 天
    int countDayOfYear(string date)
    {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        return prefixSum[month] + day;
    }
};
// @lc code=end

