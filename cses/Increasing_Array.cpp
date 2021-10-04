#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    long long currMin = 0, ans = 0;
    for(int i = 0; i < n; i++){
        long long input; cin >> input;
        currMin = max(currMin, input);
        if(input<currMin) {
            ans += currMin-input;
        }
    }
    cout << ans << endl;
}