#include "Solution.h"
#include <algorithm>

int Solution::coinChange(vector<int>& coins, int amount) {
    //以一个达不到的数值来表示正无穷
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        //状态转移方程：dp(i)=min(dp(i−面值1),dp(i−面值2),...,dp(i−面值n))+1
        //求出每一个dp[i]
        for (int coin : coins) {
            //若i<coin，什么都不做，此时dp[i]仍为MAX
            if (i>=coin) {
                dp[i] = min(dp[i], dp[i - coin]);
                //dp[i] = min(dp[i], dp[i - coin]+1);
            }
        }
        dp[i]++;
    }
    //在当前位置不是MAX的情况下返回结果
    return dp[amount] > amount ? -1 : dp[amount];
}
