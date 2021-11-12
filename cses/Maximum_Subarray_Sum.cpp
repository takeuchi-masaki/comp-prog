#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    int max_num = *max_element(a.begin(), a.end());
    if(max_num <= 0){
        cout << max_num << '\n';
        return 0;
    }

    long long curr = 0, ans = 0;
    for(int i = 0; i < n; i++){
        curr += a[i];
        if(curr <= 0) {
            curr = 0;
            continue;
        }
        ans = max(ans, curr);
    }
    cout << ans << '\n';
}