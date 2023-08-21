#include "Solution.h"
#include<vector>

// 勿混淆台阶数和方案数量，dp[i]不等于dp[i-2]+2，dp[i-2]+2的+2实际上是台阶数而非方案数，+2即混淆了台阶数和方案数
int Solution::climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    // 无意义，仅占位
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
