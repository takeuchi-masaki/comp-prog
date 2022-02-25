#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> temp(n);
    for(int& i : temp) cin >> i;
    int currBest = 1e9, currStart = 0;
    for(int start = 0; start <= n - 3; start++){
        int temp1 = temp[start], temp2 = temp[start + 2];
        int maxTemp = max(temp1, temp2);
        if(maxTemp < currBest){
            currBest = maxTemp;
            currStart = start + 1;
        }
    }
    cout << currStart << ' ' << currBest << '\n';
}