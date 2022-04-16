#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m, l;
    cin >> n >> m >> l;
    long long currCandies = m;
    for(long long buckets = l + n - 1; buckets >= l; buckets--){
        if(currCandies < buckets){
            buckets = currCandies + 1;
            continue;
        }
        long long max_candies = currCandies / buckets;
        currCandies -= max_candies * buckets;
    }
    cout << currCandies << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}