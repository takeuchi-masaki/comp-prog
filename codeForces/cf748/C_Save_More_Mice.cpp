#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> mouse(k);
    for(int i = 0; i < k; i++){
        int dist; cin >> dist;
        mouse[i] = n-dist;
    }
    sort(mouse.begin(), mouse.end());
    long long sum = 0;
    for(int i = 0; i < k; i++){
        sum += mouse[i];
        if(sum >= n){
            cout << i << '\n';
            return;
        }
    }
    cout << k << '\n';
    // 5 7 8 9
    // 5 3 2 1 = 6
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}