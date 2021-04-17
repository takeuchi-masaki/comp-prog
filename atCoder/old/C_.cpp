#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    long long res = 1e18;
    for(int i = -100; i<=100; i++){
        long long curr = 0;
        for(int j = 0; j < n; j++){
            long long add = a[j]-i;
            add*=add;
            curr+=add;
        }
        res = min(res,curr);
    }
    cout << res << '\n';
}