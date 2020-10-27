#include "Solution.h"
#include <algorithm>

int Solution::maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int inf = 1e9;
    int min_price = inf;
    int size = prices.size();
    //状态：前i天的最大收益
    int* dp = new int[size] {};
    dp[0] = 0;
    for (int i =0; i < size; i++) {
        min_price = min(min_price, prices[i]);
        if (i - 1 >= 0) {
            //在前i天中最低的价格买入，在第i天卖出，可确保卖出一定在买入之后或在同一天
			//状态转移方程
            //对最后一项选或不选，即在最后一卖或不卖
            //若不卖，则前i天最大收益成为前i-1天的最大收益
            //若卖，则以该日价格减去最低价格 
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }
     }
    return dp[size-1];
}
