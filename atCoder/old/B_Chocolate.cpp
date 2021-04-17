#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = x;
    for(int i = 0; i < n; i++){
        res+=d/a[i];
        if(d%a[i] != 0) res++;
    }
    cout << res << endl;
}