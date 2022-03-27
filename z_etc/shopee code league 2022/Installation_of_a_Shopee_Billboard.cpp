#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& a, int n)
{
    // sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
 
    int limit = 2 * sum + 1;
 
    // bottom up lookup table;
    int dp[n + 1][limit];
 
    // initialising dp table with INT_MIN
    // where, INT_MIN means no solution
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < limit; j++)
            dp[i][j] = INT_MIN;
    }
 
    // Case when diff is 0
    dp[0][sum] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
            if ((j - a[i - 1]) >= 0 && dp[i - 1][j - a[i - 1]] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
            if ((j + a[i - 1]) < limit && dp[i - 1][j + a[i - 1]] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i - 1]]);
            if (dp[i - 1][j] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    return dp[n][sum];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    cout << maxSum(a, n) << '\n';
}