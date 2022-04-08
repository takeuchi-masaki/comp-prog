#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int& i : price) cin >> i;
    for(int& i : pages) cin >> i;

    vector<int> dp(x + 1);
    for(int book = 0; book < n; book++){
        vector<int> next = dp;
        for(int cost = 0; cost < x; cost++){
            if(cost > 0) next[cost] = max(next[cost], next[cost - 1]);
            int sum = cost + price[book];
            if(sum <= x){
                next[sum] = max(next[sum], dp[cost] + pages[book]);
            }
        }
        dp = move(next);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}