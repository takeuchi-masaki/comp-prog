#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k; cin >> n >> k;
    long long curr = 1, time = 0, add = 1;
    while(curr < n){
        if(add == k){
            time += (n-curr+k-1)/k;
            curr = n;
            continue;
        }
        curr += add;
        time++;
        add = min(k, add*2);
    }
    cout << time << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}