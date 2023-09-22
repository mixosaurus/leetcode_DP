#include "Solution.h"

// ������һ��01�������⣬����������ѡ�����֣�����һ������Ϊ����һ��ı����У����ִ�СΪ������޼�ֵ����
bool Solution::canPartitionCompress(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    // �Ͳ���ż�������鲻�ɷָֱ�ӷ���false
    if (sum % 2 != 0) {
        return false;
    }
    // �ܺ͵�һ��Ϊ����������
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
