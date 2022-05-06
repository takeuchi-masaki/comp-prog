#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);

	const int MAX_NUM = 4E4 + 5;
	vector<int> palin;
	for (int i = 1; i <= MAX_NUM; i++) {
		string s = to_string(i);
		bool ok = true;
		int n = (int)s.size();
		for (int j = 0; j < n; j++) {
			if (s[j] != s[n - 1 - j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			palin.push_back(i);
		}
	}
	int psz = palin.size();

	vector<vector<long long>> dp(MAX_NUM, vector<long long>(psz + 1));
	for (int j = 0; j <= psz; j++) {
		dp[0][j] = 1;
	}
    for (int i = 1; i < MAX_NUM; i++){
        dp[i][0] = 0;
        for(int j = 1; j <= psz; j++){
            dp[i][j] = dp[i][j - 1];
            if(i - palin[j - 1] >= 0){
                dp[i][j] += dp[i - palin[j - 1]][j];
            }
            dp[i][j] %= MOD;
        }
    }

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int num;
		cin >> num;
		cout << dp[num].back() << '\n';
	}
}