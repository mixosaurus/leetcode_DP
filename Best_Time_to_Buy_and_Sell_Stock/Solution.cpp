#include "Solution.h"
#include <algorithm>

int Solution::maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int inf = 1e9;
    int min_price = inf;
    int size = prices.size();
    int* dp = new int[size] {};
    dp[0] = 0;
    //状态转移方程
    //前i天的最大收益 = max{ 前i - 1天的最大收益，第i天的价格 - 前i - 1天中的最小价格 }
    for (int i =0; i < size; i++) {
        min_price = min(min_price, prices[i]);
        if (i - 1 >= 0) {
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }
     }
    return dp[size-1];
}
