#include "Solution.h"

int Solution::minimumTotal(vector<vector<int>>& triangle) {
    int size = triangle.size();
    vector<vector<int>> dp=triangle;
    for (int i = size-2; i >=0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    return dp.front().front();
}
