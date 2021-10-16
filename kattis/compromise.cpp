#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        // cout << s[i] << endl;
    }
    vector<int> totals(m, 0);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            totals[i]+=s[j][i]-'0';
        }
        totals[i] = round((double)totals[i] / n);
    }
    for(int i:totals) cout << i;
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}