#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    vector<int> x(n);
    for(auto& i:x) cin >> i;
    for(int i = 0; i < n; i++){
        sum += 2 * min(x[i],abs(k-x[i]));
    }
    cout << sum << endl;
}