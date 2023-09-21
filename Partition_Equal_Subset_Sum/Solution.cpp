#include "Solution.h"

bool Solution::canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    sum = sum / 2;
    vector<int> dp(sum + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = sum; j >= nums[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    if (dp[sum] == sum) return true;
	return false;
}
