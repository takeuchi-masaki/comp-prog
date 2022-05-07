#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a) cin >> i;
    vector<bool> okLow(n, false), okHigh(n, false);
    int maxI = a[0];
    okLow[0] = true;
    for(int i = 1; i < n; i++){
        if(a[i] > maxI) {
            okLow[i] = true;
            maxI = a[i];
        }
    }
    int minI = a[n-1];
    okHigh[n-1] = true;
    for(int i = n-2; i>=0; i--){
        if(a[i] < minI){
            okHigh[i] = true;
            minI = a[i];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(okHigh[i] && okLow[i]) ans++;
    }
    cout << ans << endl;
}