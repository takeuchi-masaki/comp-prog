#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1),b(n);
    long long res = 0;
    for(int i = 0; i < n+1; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = n-1; i >= 0; i--){
        int diff = min(b[i],a[i+1]);
        res += diff;
        b[i]-= diff;
        if(b[i]>0){
            diff = min(b[i],a[i]);
            a[i]-=diff;
            res+=diff;
        }
    }
    std::cout << res << endl;
}