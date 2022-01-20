#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    for(int i = 105; i <= n; i+=2){
        int curr = 0;
        for(int div = 1; div <= i; div++){
            if(i % div == 0) curr++;
        }
        if(curr == 8) ans++;
    }
    cout << ans << '\n';
}