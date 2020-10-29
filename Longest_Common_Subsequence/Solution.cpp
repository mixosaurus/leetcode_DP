#include "Solution.h"
#include<array>

int Solution::longestCommonSubsequence(string text1, string text2) {
    //�൱����������������Ϊ0���к��У���ܱ߽����
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1,0));
    //��1��ʼѭ����ʹ��i-1��j-1Ϊ0
    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            //ʹ��at������ֹԽ��
            if (text1.at(i-1) == text2.at(j-1)) {
                //��ĩԪ����ͬ��ת�Ƶ�����Ԫ��
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                //��ĩԪ�ز���ͬ��ת�Ƶ������ϲ�Ԫ��
                //����abc��abd��ת��Ϊab��abd��abc��ab�е����ֵ
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp.back().back();
}
