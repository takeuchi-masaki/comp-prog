#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long row, col; cin >> row >> col;
    bool rowLarger = row >= col;
    long long region = max(row, col);
    if(rowLarger){
        if(region&1){
            long long totalBefore = (region - 1) * (region - 1);
            cout << totalBefore + min(row, col) << '\n';
        } else {
            long long totalBefore = region * region;
            cout << totalBefore - (min(row, col)-1) << '\n';
        }
    }
    else if(region%2 == 0){
        long long totalBefore = (region - 1) * (region - 1);
        cout << totalBefore + min(row, col) << '\n';
    } else {
        long long totalBefore = region * region;
        cout << totalBefore - (min(row, col)-1) << '\n';
    }
}

int main(){
    // freopen("test_input.txt","r",stdin); freopen("user_out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}