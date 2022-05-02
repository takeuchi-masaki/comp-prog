#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<long long, long long>> numIdx(n);
    for(int i = 0; i < n; i++){
        cin >> numIdx[i].first;
        numIdx[i].second = i;
    }
    long long s = 0;
    for(int i = 0; i < k; i++){
        s += numIdx[i].first;
    }
    sort(numIdx.rbegin(), numIdx.rend());
    
    long long s2 = 0;
    for(int i = 0; i < k; i++){
        s2 += numIdx[i].first;
    }
    cout << s << ' ' << s2 << '\n';
    if(s2 <= s) {
        cout << "-1\n";
        return;
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    solve();
}