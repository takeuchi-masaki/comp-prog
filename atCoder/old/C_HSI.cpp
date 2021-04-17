#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    long long res = n-m;
    res*=100;
    res+=1900*m;
    long long odds = 1<<m;
    res*=odds;
    cout << res << '\n';
}