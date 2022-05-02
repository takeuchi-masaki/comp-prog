#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n = 26;
    vector<pair<char, char>> vp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            vp.push_back({i + 'a', j + 'a'});
        }
    }
    sort(vp.begin(), vp.end());
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string q;
        cin >> q;
        for(int j = 0; j < (int)vp.size(); j++){
            if(q[0] == vp[j].first && q[1] == vp[j].second) {
                cout << j + 1 << '\n';
                break;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    solve();
}