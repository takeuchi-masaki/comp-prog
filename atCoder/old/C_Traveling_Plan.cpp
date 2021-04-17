#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    const int INF = 1E9;
    vector<int> a(n); // coordinate
    for(int& i:a)cin>>i;
    int totSum = abs(a[0]);
    for(int i = 1; i < n; i++){
        totSum += abs(a[i-1]-a[i]);
    }
    totSum += abs(a[n-1]);
    string out = "";
    {
        int res = totSum;
        res -= abs(a[0]);
        res -= abs(a[1]-a[0]);
        res += abs(a[1]);
        cout << res << endl;
    }
    for(int i = 1; i < n-1; i++){
        int res = totSum;
        res -= abs(a[i-1]-a[i]);
        res -= abs(a[i]-a[i+1]);
        res += abs(a[i+1]-a[i-1]);
        cout << res << endl;
    }
    totSum -= abs(a[n-1]);
    totSum -= abs(a[n-1]-a[n-2]);
    totSum += abs(a[n-2]);
    cout << totSum << endl;
}