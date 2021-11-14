#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, a; cin >> n >> k >> a;
    int ans = a + (k % n) - 1;
    ans %= n;
    cout << (ans == 0 ? n : ans) << '\n';
}