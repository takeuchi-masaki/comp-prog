#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        int curr = 0;
        while(num%2 == 0){
            num/=2;
            curr++;
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
}