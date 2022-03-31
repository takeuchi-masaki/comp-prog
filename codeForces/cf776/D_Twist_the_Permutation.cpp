#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1), pos(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        pos[a[i]] = i;
    }

    vector<vector<int>> larger_pref(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            larger_pref[i][j] = (a[j] > i) + larger_pref[i][j - 1];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << larger_pref[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    vector<int> ans;
    if(pos.back() == n) ans.push_back(0);
    else ans.push_back(pos.back());
    for(int i = n - 1; i > 1; i--){
        int curr = -99;
        int targetPos = pos[i + 1] - 1;
        if(targetPos == 0) targetPos += n;

        if(targetPos > pos[i]){
            curr = pos[i] + (n - targetPos);
            curr -= larger_pref[i][pos[i]] + (larger_pref[i][n] - larger_pref[i][targetPos]);
        } else {
            curr = pos[i] - targetPos;
            curr -= larger_pref[i][pos[i]] - larger_pref[i][targetPos];
        }
        if(curr == i) curr = 0;
        ans.push_back(curr);
    }
    ans.push_back(0);
    
    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << *it << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}