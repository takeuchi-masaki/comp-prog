#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    vector<long long> prefix(n);
    long long curr = 0;
    for(int i = 0; i < n; i++){
        curr+=a[i];
        prefix[i]=curr;
    }
    long long l=prefix[0], r=prefix[n-1]-prefix[0];
    long long res = abs(r-l);
    for(int i = 1; i<n-2; i++){
        l = prefix[i], r = prefix[n-1]-l;
        long long diff = abs(r-l);
        res = min(res,diff);
    }
    cout << res << '\n';
}