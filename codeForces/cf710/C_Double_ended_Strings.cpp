#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}

int lcs(string X, string Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

void solve(){
    string a, b; cin >> a >> b;
    int m = a.length(), n = b.length();
    int longest = lcs(a, b, m, n);
    // cout << longest << "\n";
    cout << (m-longest)+(n-longest) << "\n";
    // cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}