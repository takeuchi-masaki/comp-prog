#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>> student(n, vector<int>(5));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> student[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == j) continue;
            bool ok = true;
            int dayI = 0, dayJ = 0;
            for(int k = 0; k < n; k++){
                if(student[k][i] == 0 
                && student[k][j] == 0) {
                    ok = false;
                    break;
                }
                dayI += student[k][i];
                dayJ += student[k][j];
            }
            if(dayI*2 < n || dayJ*2 < n) ok = false;
            if(ok){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}