#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a)cin>>i;
    // sort(a.begin(),a.end(),std::greater<int>());
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum+=a[i];
    }
    long long res = sum;
    long long sum2 = 0;
    for(int i = 0; i < n; i++){
        sum2+=a[i];
        long long diff = abs(sum2-(sum-sum2));
        res = min(diff,res);
    }
    cout << res << endl;
}