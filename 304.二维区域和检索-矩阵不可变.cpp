/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        data.clear();
        if (matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();

        data = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                data[i][j] = matrix[i - 1][j - 1] + data[i - 1][j] + data[i][j - 1] - data[i - 1][j - 1];
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return data[row2 + 1][col2 + 1] - data[row2 + 1][col1] - data[row1][col2 + 1] + data[row1][col1];
    }

private:
    vector<vector<int>> data;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
