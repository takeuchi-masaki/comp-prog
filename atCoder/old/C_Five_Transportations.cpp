#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n;
    vector<long long> a(5);
    cin >> n;
    for(int i = 0; i < 5; i++) cin >> a[i];
    long long res = 4, min_transport = *min_element(a.begin(),a.end());
    res+=(n+min_transport-1)/min_transport; // ceil
    cout << res << '\n';
}