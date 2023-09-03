#include <iostream>
#include <vector>

using namespace std;

int minInsert(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cout << "请输入一个字符串: ";
    cin >> s;

    int minInsertions = minInsert(s);
    cout << "需要插入的最少次数: " << minInsertions << endl;

    return 0;
}
