#include "Solution.h"

//���»��������ƶ��������ڳɻ������
//��������Ϊ·�������������ϵ�����������µ�����·������ͬ
//��ˣ������������µ����ϣ����������
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid.front().size();
    //�������飬��һά����ʼ���൱�ڶ�ά����������
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
            //����j-1������jÿ�δӵڶ���Ԫ�ؿ�ʼ����
            //obstacleGrid[i][j - 1] == 0��ȥ��
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                //cout << "i: " << i << " j: " << j << ", " << f[j] << " + " << f[j - 1] << " = ";
                f[j] =f[j] + f[j - 1];
                ////cout << f[j] << endl;
            }
        }
    }
    return f.back();
}
