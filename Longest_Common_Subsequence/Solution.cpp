#include "Solution.h"
#include<array>

int Solution::longestCommonSubsequence(string text1, string text2) {
    //相当于在最左和最上添加为0的列和行，规避边界情况
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,0));
    //从1开始循环，使得i-1或j-1为0
    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            //使用at函数防止越界
            if (text1.at(i-1) == text2.at(j-1)) {
                //若末元素相同，转移到左上元素
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                //若末元素不相同，转移到左侧或上侧元素
                //即若abc和abd，转移为ab和abd或abc和ab中的最大值
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp.back().back();
}
