#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//63. ²»Í¬Â·¾¶ II
int main() {
	Solution solution;
	vector<vector<int>> obstacleGrid = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
	system("pause");
	return 0;
}
