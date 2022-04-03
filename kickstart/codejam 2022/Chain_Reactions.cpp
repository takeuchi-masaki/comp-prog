#include <bits/stdc++.h>
using namespace std;

long long ans;

int simplify(int i, vector<int>& a, vector<vector<int>>& to){
    if(to[i].empty()) return a[i];
    long long currSum = 0;
    int currMin = 1e9 + 5;
    for(int prev : to[i]){
        int val = simplify(prev, a, to);
        currMin = min(currMin, val);
        currSum += val;
    }
    if(to[i].size() >= 2) ans += currSum - currMin;
    return max(currMin, a[i]);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), to_void;
    for(int& i : a) cin >> i;
    vector<vector<int>> to(n);

    for(int i = 0; i < n; i++){
        int next; cin >> next;
        next--;
        if(next != -1) {
            to[next].push_back(i);
        } else {
            to_void.push_back(i);
        }
    }
    
    ans = 0;
    for(int i : to_void){
        ans += simplify(i, a, to);
    }
    cout << ans << '\n';
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