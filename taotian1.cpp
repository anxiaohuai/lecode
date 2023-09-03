#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int countSameCharSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 初始化单个字符的情况
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // 开始填充dp数组

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // 如果首尾字符相同，可以将首尾字符构成新的子序列
            if (s[i] == s[j]) {
                
                dp[i][j] = (dp[i][j] + dp[i][j - 1] + 1) % MOD;
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
            // 不考虑当前字符，将其贡献加到下一个状态
            // dp[i][j] = (dp[i][j] + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            dp[i][j] = dp[i][j-1] + dp[i][j];
            cout<<"  "<<i<<j<<"dp = "<<dp[i][j]<<endl;
        }

    }
    // dp[0][n-1] 表示整个字符串的满足条件的子序列数量
    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;

    int result = countSameCharSubsequences(s);
    cout << result << endl;

    return 0;
}
