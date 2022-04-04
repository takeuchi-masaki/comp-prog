#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    if(mx < k){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int currgcd = a[0];
    for(int i : a) currgcd = gcd(currgcd, i);
    if(k % currgcd == 0){
        cout << "POSSIBLE\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}