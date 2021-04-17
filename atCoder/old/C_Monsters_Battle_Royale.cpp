#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    int prev = a[0];
    for(int i = 1; i < n; i++){
        prev = gcd(prev, a[i]);
    }
    cout << prev << '\n';
}