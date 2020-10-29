#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//1143. 最长公共子序列
int main() {
	Solution solution;
	string text1 = "abcba";
	string text2 = "abcbcba";
	cout << solution.longestCommonSubsequence(text1,text2) << endl;
	system("pause");
	return 0;
}
