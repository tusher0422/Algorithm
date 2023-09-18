#include <bits/stdc++.h>
using namespace std;
int main() {
    int S, N;
    cin >> S >> N;
    vector<int> size(N), value(N);
    for (int i = 0; i < N; i++) {
        cin >> size[i] >> value[i];
    }
    vector<int> dp(S + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = S; j >= size[i]; j--) {
            dp[j] = max(dp[j], dp[j - size[i]] + value[i]);
        }
    }
    cout << dp[S] << endl; 
    return 0;
}