#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> r(n);
    for(int& i:r) cin >> i;
    sort(r.begin(),r.end());
    double res = 0.0;
    int start = n-k, end = n-1;
    for(int i = start; i <= end; i++){
        res = (res+r[i])/2;
    }
    cout << fixed << setprecision(10) << res << '\n';
}