#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int&i:a) cin >> i;
    for(int&i:b) cin >> i;
    long long diff = 0;
    for(int i = 0; i < n; i++){
        diff += abs(a[i]-b[i]);
    }
    if(diff <= k && (diff&1)==(k&1)){
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}