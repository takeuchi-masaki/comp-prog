#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    int hMin = h[0], hMax;
    hMax = h[k-1];
    int res = hMax - hMin;
    int count = 0;
    for(int i = k; i < n; i++){
        hMin=h[++count];
        hMax=h[i];
        res = min(res,hMax-hMin);
    }
    cout << res << endl;
}