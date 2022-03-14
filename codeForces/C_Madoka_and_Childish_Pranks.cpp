#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> vs(n);
    for(string& s : vs) cin >> s;
    if(vs[0][0] == '1'){
        cout << "-1\n";
        return;
    }
    vector<vector<int>> ans;
    vector<vector<bool>> curr_grid(n, vector<bool>(m));
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(vs[i][j] == '0') continue;
            if(i > 0){
                vector<int> curr = {
                    i - 1, j, 
                    i, j
                };
                ans.push_back(curr);
            } else if(j > 0){
                vector<int> curr = {
                    i, j - 1,
                    i, j
                };
                ans.push_back(curr);
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto v : ans){
        for(int i : v){
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}