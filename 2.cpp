#include <iostream>
using namespace std;

const int MOD = 10000000;

int main() {
    int n,m;
    cin>>n>>m;

    // 创建一个三维数组来存储计算结果
    int dp[100][100][100] = {0};

    // 初始化第一维数组
    for (int i = 1; i <= m; i++) {
        if (i <= n) {
            dp[1][i][i] = 1;
        }
    }

    // 动态规划计算好数组数量
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = 1; l <= m; l++) {
                    if (k + l <= n && (k + l) % i == 0) {
                        dp[i][j][k + l] = (dp[i][j][k + l] + dp[i][j - 1][k]) % MOD;
                    }
                }
            }
        }
    }

    // 计算好数组的数量
    int result = 0;
    for (int i = 1; i <= m; i++) {
        result = (result + dp[n][i][n]) % MOD;
    }

    cout << result << endl;
    return 0;
}
