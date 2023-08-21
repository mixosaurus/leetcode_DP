#include "Solution.h"
#include<vector>

// �����̨�����ͷ���������dp[i]������dp[i-2]+2��dp[i-2]+2��+2ʵ������̨�������Ƿ�������+2��������̨�����ͷ�����
int Solution::climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    // �����壬��ռλ
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
