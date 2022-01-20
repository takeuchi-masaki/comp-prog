#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, x;
    while(cin >> n >> x){
        if(n == 0) break;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    if(i + j + k == x) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}