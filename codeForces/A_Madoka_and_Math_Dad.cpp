#include <bits/stdc++.h>
using namespace std;

vector<int> n_nec(1001);

// cnt necessary for digit
/*
    1: 1
    2: 3, 21
    3: 4, 121
    4: 6, 2121
    5: 7, 12121
*/

void solve(){
    int n; cin >> n;
    auto it = lower_bound(n_nec.begin(), n_nec.end(), n);
    if(*it != n) {
        it--;
    }
    int digits = it - n_nec.begin();
    // cout << digits << '\n';
    bool one;
    if(digits&1){
        one = (*it == n);
    } else {
        one = false;
    }
    string ans{};
    for(int i = 0; i < digits; i++){
        if(one){
            ans.push_back('1');
        } else {
            ans.push_back('2');
        }
        one ^= 1;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    n_nec[1] = 1;
    for(int i = 2; i <= 1000; i++){
        n_nec[i] = n_nec[i - 1] + 1 + (i % 2 == 0);
    }

    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}