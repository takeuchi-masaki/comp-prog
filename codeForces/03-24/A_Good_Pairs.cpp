#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int i_min = 1e9 + 5, j_max = -1e9 - 5;
    int i_ans, j_ans;

    for(int i = 0; i < n; i++){
        if(a[i] < i_min){
            i_min = a[i];
            i_ans = i + 1;
        }
        if(a[i] > j_max){
            j_max = a[i];
            j_ans = i + 1;
        }
    }
    cout << i_ans << ' ' << j_ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}