#include "Solution.h"

//向下或者向右移动，不存在成环的情况
//本题所求为路径数量，从左上到右下与从右下到左上路径数相同
//因此，可视作从右下到左上，并依此求解
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid.front().size();
    //滚动数组，该一维数组始终相当于二维数组最新行
    vector <int> f(m);
    if (obstacleGrid[0][0] == 0) {
        f[0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[i][j] == 1) {
                f[j] = 0;
                continue;
            }
            //由于j-1条件，j每次从第二个元素开始递增
            //obstacleGrid[i][j - 1] == 0可去掉
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                //cout << "i: " << i << " j: " << j << ", " << f[j] << " + " << f[j - 1] << " = ";
                f[j] =f[j] + f[j - 1];
                ////cout << f[j] << endl;
            }
        }
    }
    return f.back();
}
