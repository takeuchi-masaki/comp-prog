#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> ans(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = n; i >= 1; i--){
        int parity = 0;
        for(int j = (i<<1); j <= n; j += i){
            if(ans[j]) parity ^= 1;
        }
        ans[i] = (parity != a[i]);
    }

    cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
    for(int i = 1; i <= n; i++){
        if(ans[i]) cout << i << ' ';
    }
    cout << '\n';
}