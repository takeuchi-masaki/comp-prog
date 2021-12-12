#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    long long h;
    cin >> n >> h;
    vector<int> time(n);
    for(int& i : time) cin >> i;
    vector<int> diffs(n);
    int maxDiff = 0;
    for(int i = 0; i < n - 1; i++){
        diffs[i] = time[i + 1] - time[i];
        maxDiff = max(maxDiff, diffs[i]);
    }
    diffs.back() = maxDiff;
    
    long long regularMax = accumulate(diffs.begin(), diffs.end(), 0ll);
    if(h > regularMax){
        long long diff = h - regularMax;
        cout << diff + maxDiff << '\n';
        return;
    }
    
    long long l = 0, r = h;
    while(r - l > 1){
        long long mid = (l + r)/2;
        long long damage = 0;
        for(int i : diffs){
            damage += min((long long) i, mid);
        }
        if(damage >= h){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}