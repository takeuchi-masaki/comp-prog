#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> d(n), m(n);
    for(int& i : d) cin >> i;
    
    long long sum = d.back();
    for(int i = 0; i < n - 2; i++){
        sum += d[i];
    }
    sum -= d[n - 2];
    for(int i = 1; i <= n - 4; i += 2){
        sum -= 2 * d[i];
    }
    m[0] = sum;
    
    for(int i = 1; i < n; i++){
        m[i] = 2 * (d[i - 1] - m[i - 1] / 2);
    }
    for(int i : m) cout << i << ' ';
    cout << '\n';
}