#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k; cin >> k;
    vector<int> xs, ys;
    for(int i = 0; i < 2*k; i++){
        int x, y; cin >> x >> y;
        xs.push_back(x), ys.push_back(y);
    }
    sort(xs.begin(), xs.end()), sort(ys.begin(), ys.end());
    cout << xs[k-1] << ' ' << ys[k-1] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}