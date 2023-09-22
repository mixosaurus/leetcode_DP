#include "Solution.h"

// 可视作一个01背包问题，即从数组中选出数字，放入一个容量为数组一半的背包中，数字大小为体积，无价值属性
bool Solution::canPartitionCompress(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    // 和不是偶数，数组不可分割，直接返回false
    if (sum % 2 != 0) {
        return false;
    }
    // 总和的一半为背包的容量
    int cap = sum / 2;
    vector<int> dp(cap + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = cap; j >= nums[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    if (dp[cap] == cap) return true;
	return false;
}

bool Solution::canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
        return false;
    }
    int cap = sum / 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= nums.size(); i++) {
        for (int j = 1; j <= cap; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[nums.size()][cap] == cap) {
        return true;
    }
    return false;
}
