#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    long long res = 0;
    cin >> res;
    for(int i = 1; i < n; i++){
        long long t; cin >> t;
        res = lcm(res,t);
    }
    cout << res << '\n';
}