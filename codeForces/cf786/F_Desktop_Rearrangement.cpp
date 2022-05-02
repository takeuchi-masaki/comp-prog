#include <bits/stdc++.h>
using namespace std;

void solve() {
	int R, C, q;
	cin >> R >> C >> q;
	vector<string> vs(R);
	for (string& s: vs) cin >> s;

    int icon_cnt = 0;
    vector<int> currSum(C);
    for(int j = 0; j < C; j++){
        for(int i = 0; i < R; i++){
            if(vs[i][j] == '*'){
                currSum[j]++;
                icon_cnt++;
            }
        }
    }
    int ans = 0;
    int completely_filled = icon_cnt / R;
    int partially_filled = icon_cnt % R;

    for(int j = 0; j < completely_filled; j++){
        ans += R - currSum[j];
    }
    if(partially_filled){
        for(int i = 0; i < partially_filled; i++){
            if(vs[i][completely_filled + 1] == '.') {
                ans++;
            }
        }
    }

	for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        int next_complete, next_partial;
        if(vs[r][c] == '*') {
            icon_cnt--;
            next_complete = icon_cnt / R;
            next_partial = icon_cnt % R;
            if(partially_filled == 0){
                
            } else {
            
            }
            vs[r][c] = '.';
        } else {
            icon_cnt++;
            next_complete = icon_cnt / R;
            next_partial = icon_cnt % R;
            if(next_partial == 0){
                
            } else {
                
            }
            vs[r][c] = '*';
        }
        completely_filled = next_complete;
        partially_filled = next_partial;
        cout << ans << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}