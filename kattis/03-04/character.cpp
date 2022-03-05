#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    // all combinations of n people = 2^n (1<<n)
    // subtract selecting 1 person (n)
    // subtract selecting no people (1)
    long long ans = (1<<n) - n - 1;
    cout << ans << '\n';
}