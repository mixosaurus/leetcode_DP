#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//121. 买卖股票的最佳时机
int main() {
	Solution solution;
	//vector<int> prices = { 7,1,5,3,6,4 };
	vector<int> prices = { 1, 2 };
	cout << solution.maxProfit(prices) << endl;
	system("pause");
	return 0;
}
