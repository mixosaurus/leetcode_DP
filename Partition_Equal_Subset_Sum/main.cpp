#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//416. 分割等和子集
int main() {
	Solution solution;
	vector<int> nums = { 1,5,11,5 };
	cout << solution.canPartition(nums) << endl;
	system("pause");
	return 0;
}
