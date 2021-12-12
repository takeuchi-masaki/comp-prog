#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 
    vector<int> a(n);
    bool haveZero = false;
    int minVal = 1e9, cntNegative = 0;
    long long sum = 0;
    for(int& i : a) {
        cin >> i;
        if(i == 0) haveZero = true;
        if(i < 0) cntNegative++;
        minVal = min(minVal, abs(i));
        sum += abs(i);
    }
    
    if(haveZero || (cntNegative % 2 == 0)){
        cout << sum << '\n';
    } else {
        cout << sum - 2*minVal << '\n';
    }
}