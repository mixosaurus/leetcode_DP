#include "Solution.h"

int Solution::rob(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
    int size = nums.size();
    if (size == 1) {
        return nums.front();
    }
    //״̬��͵��ǰi���������õ���߽��
    int* dp = new int[size] {};
    dp[0] = nums.front();
    dp[1] = max(nums[0],nums[1]);
    for (int i = 2; i < size; i++) {
        //״̬ת�Ʒ���
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[size - 1];
}
