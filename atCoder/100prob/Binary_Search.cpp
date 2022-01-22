#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> s(n);
    for(int& i : s) cin >> i;
    // sort(s.begin(), s.end());

    int ans = 0;
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int target; cin >> target;
        ans += binary_search(s.begin(), s.end(), target);
    }
    cout << ans << '\n';
}