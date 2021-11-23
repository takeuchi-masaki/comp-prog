#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> h(n);
    for(int & i : h) cin >> i;
    const int INF = 1e9;
    vector<long long> minCost(n, INF);
    minCost[0] = 0, minCost[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        minCost[i] = min(minCost[i - 1] + abs(h[i] - h[i - 1]),
                         minCost[i - 2] + abs(h[i] - h[i - 2])
                        );
    }
    // for(int i : minCost) cout << i << ' ';
    // cout << '\n';
    cout << minCost[n - 1] << '\n';
}