#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(const string &str1, const string &str2) {
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return lcs;
}

int main() {
    string S1, S2;

    //cout << "Enter the DNA strand S1: ";
    cin >> S1;

    //cout << "Enter the DNA strand S2: ";
    cin >> S2;

    string S3 = longestCommonSubsequence(S1, S2);

    cout << "LCS: " << S3 << endl;
    cout << "LCS Length: " << S3.length() << endl;

    return 0;
}