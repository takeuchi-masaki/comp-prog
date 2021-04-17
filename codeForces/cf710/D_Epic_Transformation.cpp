#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    map<int,int> nums;
    int most = 0;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        nums[temp]++;
        // most = max(most, nums[temp]);
    }
    for(auto [x,y]:nums){
        most = max(most, y);
    }
    int res = min(n/2, n-most);
    cout << n - res*2 << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}