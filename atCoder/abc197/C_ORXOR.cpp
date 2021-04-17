#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    int res = 1<<30;
    for(long long bit = 0; bit < (1<<n-1); bit++){
        int curr = 0, currOR = 0;
        for(int i = 0; i < n-1; i++){
            currOR |= a[i];
            if((bit>>i)&1){
                curr ^= currOR;
                currOR = 0;
            }
        }
        currOR |= a[n-1];
        curr ^= currOR;
        res = min(res, curr);
    }
    cout << res << '\n';
}