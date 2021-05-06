#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    string s;
    cin >> n >> s >> q;
    bool swap = false;
    for(int i = 0; i < q; i++){
        int t, a, b; cin >> t >> a >> b;
        if(t == 1){
            a--, b--;
            if(swap){
                if(a>=n) {
                    a-=n;
                } else {
                    a+=n;
                }
                if(b>=n){
                    b-=n;
                } else {
                    b+=n;
                }
            }
            char temp = s[a];
            s[a] = s[b];
            s[b] = temp;
        } else {
            swap = !swap;
        }
    }
    if(swap){
        for(int i = 0; i < n; i++){
            char temp = s[i];
            s[i] = s[n+i];
            s[n+i] = s[i];
        }
    }
    cout << s << endl;
}