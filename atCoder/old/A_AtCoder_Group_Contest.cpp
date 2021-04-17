#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(3*n);
    for(int i = 0; i < 3*n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long res = 0;
    int l = 0, r = 3*n-1;
    while(l<r){
        res+=a[r-1];
        l++;
        r-=2;
    }
    cout << res << endl;
}