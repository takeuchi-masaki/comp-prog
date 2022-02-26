#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> temp(n);
    for(int& i : temp) cin >> i;

    int bestTemp = 1e9, day = 0;
    for(int start = 0; start <= n - 3; start++){
        int maxTemp = max(temp[start], temp[start + 2]);
        if(maxTemp < bestTemp){
            bestTemp = maxTemp;
            day = start + 1; // 1 indexed day
        }
    }
    cout << day << ' ' << bestTemp << '\n';
}