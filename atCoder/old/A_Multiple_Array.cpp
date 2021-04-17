#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    long long res = 0;
    for(int i = n-1; i>=0; i--){
        a[i]+=res;
        long long target = ceil((double)a[i]/b[i]);
        target*=b[i];
        res+=target-a[i];
    }
    cout << res << '\n';
}