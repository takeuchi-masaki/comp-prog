#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> h(n), left(n, -1), right(n, -1);
    for(int& i:h) cin >> i;
    for(int i = 1; i < n-1; i++){
        left[i] = max(left[i-1], h[i-1]);
    }
    for(int i = n-2; i > 0; i--){
        right[i] = max(right[i+1], h[i+1]);
    }
    // for(int i:left) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for(int i:right) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    int res = 0;
    for(int i = 1; i < n-1; i++){
        res = max(res, min(left[i], right[i])-h[i]);
    }
    cout << res << endl;
}