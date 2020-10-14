#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//322. ¡„«Æ∂“ªª
int main() {
	Solution solution;
	vector<int>coins = { 2,5,10,1 };
	int amount = 27;
	cout << solution.coinChange(coins, amount) << endl;
	system("pause");
	return 0;
}
