#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> s(n), b(n);

    for(int i = 0; i < n; i++){
        cin >> s[i] >> b[i];
    }
    long long ans = 1e9+5;
    for(int bit = 1; bit < (1<<n); bit++){
        long long sour = 1, bitter = 0;
        for(int i = 0; i < n; i++){
            if(bit>>i&1){
                sour*=s[i];
                bitter+=b[i];
            }
        }
        ans = min(ans, abs(sour-bitter));
    }
    cout << ans << endl;
}