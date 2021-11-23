#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int & i : h) cin >> i;
    const int INF = 1e9;
    vector<int> minCost(n, INF);
    minCost[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k && i + j < n; j++){
            minCost[i + j] = 
                min(minCost[i + j], 
                    minCost[i] + abs(h[i + j] - h[i])
                );
        }
    }
    cout << minCost[n - 1] << '\n';
}