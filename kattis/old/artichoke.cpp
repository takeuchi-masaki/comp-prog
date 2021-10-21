#include <bits/stdc++.h>
using namespace std;

int p, a, b, c, d, n;

long double price(int k){
    return (sinl(a*k+b) + cosl(c*k+d) + 2)*p;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> p >> a >> b >> c >> d >> n;
    long double currMin = 1e9, currMax = 0, maxDiff = 0;
    vector<long double> prices(n);
    for(int i = 0; i < n; i++){
        prices[i] = price(i+1);
        // cout << prices[i] << ' ';
    }
    // cout << endl << endl;
    vector<long double> maxs(n), mins(n);
    maxs[0] = prices[0], mins[n-1] = prices[n-1];
    for(int i = 1; i < n; i++){
        maxs[i] = max(maxs[i-1], prices[i]);
    }
    for(int i = n-2; i>=0; i--){
        mins[i] = min(mins[i+1], prices[i]);
    }
    // for(int i = 0; i < n; i++){
    //     cout << maxs[i] << ' ';
    // }
    // cout << endl << endl;
    // for(int i = 0; i < n; i++){
    //     cout << mins[i] << ' ';
    // }
    // cout << endl << endl;
    for(int i = 0; i < n-1; i++){
        maxDiff = max(maxDiff, maxs[i]-mins[i+1]);
    }
    cout << fixed << setprecision(9);
    cout << maxDiff << endl;
}