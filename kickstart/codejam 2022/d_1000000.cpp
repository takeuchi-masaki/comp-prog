#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());

    int l = 1, r = n + 1;
    while(r - l > 1){
        int mid = l + (r - l)/2;
        int curr = mid;
        bool ok = true;
        for(auto it = a.rbegin(); it != a.rend(); it++){
            if(*it < curr){
                ok = false;
                break;
            }
            curr--;
        }
        if(ok){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}