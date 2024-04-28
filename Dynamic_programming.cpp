#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<int, int> partition(vector<int>& A) {
    int n = A.size();
    int totalSum = 0;
    for (int num : A) {
        totalSum += num;
    }

    int targetSum = totalSum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= A[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i - 1]] + A[i - 1]);
            }
        }
    }

    int sum1 = dp[n][targetSum];
    int sum2 = totalSum - sum1;

    int n1 = n, n2 = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (dp[i][targetSum] == sum1) {
            n1 = i;
            n2 = n - n1;
            break;
        }
    }

    return {abs(n1 - n2), abs(sum1 - sum2)};
}

int main() {
    vector<int> A = {2, 5, 7, 3, 1, 8}; // 例子输入
    pair<int, int> result = partition(A);
    cout << "n1 - n2 = " << result.first << endl;
    cout << "|S1 - S2| = " << result.second << endl;

    return 0;
}
