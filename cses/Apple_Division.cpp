#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n);
    for(int & i : arr) cin >> i;
    long long currMin = 1e18;
    for(int mask = 0; mask < (1<<n); mask++){
        long long a = 0, b = 0;
        for(int bit = 0; bit < n; bit++){
            if(mask >> bit & 1) a += arr[bit];
            else b += arr[bit];
        }
        currMin = min(currMin, abs(a-b));
    }
    cout << currMin << '\n';
}