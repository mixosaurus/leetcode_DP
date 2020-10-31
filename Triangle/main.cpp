#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//120. 三角形最小路径和
int main() {
	Solution solution;
	vector<vector<int>> triangle = {
		{2} ,
		{3,4 },
		{6,5,7},
		{4,1,8,3}
	};
	cout << solution.minimumTotal(triangle) << endl;
	system("pause");
	return 0;
}
