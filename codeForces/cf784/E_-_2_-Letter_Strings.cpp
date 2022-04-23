#include <bits/stdc++.h>
using namespace std;

const long long LETTER_CNT = 'k' - 'a' + 1;

void solve() {
	long long n;
	cin >> n;
	vector<string> vs(n);
	for (string& s: vs) cin >> s;
    map<string, int> m;
    for(string s: vs) m[s]++;
    long long subtract = 0;
    for(auto& [str, cnt]: m){
        if(cnt > 1){
            subtract += (long long)cnt * (cnt - 1) / 2;
        }
    }

	vector<vector<long long>> cnt1(n, vector<long long>(LETTER_CNT)), cnt2(n, vector<long long>(LETTER_CNT));
	for (long long i = n - 1; i >= 0; i--) {
		cnt1[i][vs[i][0] - 'a']++;
		cnt2[i][vs[i][1] - 'a']++;
	}
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < LETTER_CNT; j++){
    //         cout << cnt2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

	vector<vector<long long>> pref(n, vector<long long>(LETTER_CNT)), pref2(n, vector<long long>(LETTER_CNT));
    pref[n - 1] = cnt1[n - 1];
    pref2[n - 1] = cnt2[n - 1];
    for(long long i = n - 2; i >= 0; i--){
        pref[i] = pref[i + 1];
        pref2[i] = pref2[i + 1];
        for(long long j = 0; j < LETTER_CNT; j++){
            pref[i][j] += cnt1[i][j];
            pref2[i][j] += cnt2[i][j];
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < LETTER_CNT; j++){
    //         cout << pref2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    long long ans = 0;
    for(long long i = 0; i < n - 1; i++){
        // cout << pref[i + 1][vs[i][0] - 'a'] << ' ';
        // cout << pref2[i + 1][vs[i][1] - 'a'] << '\n';
        ans += pref[i + 1][vs[i][0] - 'a'];
        ans += pref2[i + 1][vs[i][1] - 'a'];
    }
    // cout << ans << ' ' << subtract << '\n';
    cout << ans - subtract*2 << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	long long T = 1;
	cin >> T;
	for (long long i = 1; i <= T; i++) {
		solve();
	}
}