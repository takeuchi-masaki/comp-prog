#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a)cin>>i;
    if(n<=2) {
        cout << "0\n";
        return;
    }
    // n, m, s, c to gen array
    // a1 = s mod m
    // ai = (ai-1 + c)mod m
    bool noDecr = true;
    int m = -1, c = -1;
    for(int i = 1; i < n; i++){
        int diff = a[i]-a[i-1];
        if(diff<0){
            if(c!=-1){
                int mod = a[i-1]+c - a[i];
                if(m!=-1){
                    if(m!=mod){
                        cout << "-1\n";
                        return;
                    }
                } else {
                    m = mod;
                }
            }
        } else if(c==-1){
            c = diff;
        } else {
            if(diff!=c){
                cout << "-1\n";
                return;
            }
        }
    }
    for(int i = 1; i < n; i++){
        int diff = a[i]-a[i-1];
        if(diff<0){
            noDecr = false;
            if(c!=-1){
                int mod = a[i-1]+c - a[i];
                if(m!=-1){
                    if(m!=mod){
                        cout << "-1\n";
                        return;
                    }
                } else {
                    m = mod;
                }
            }
        } else if(c==-1){
            c = diff;
        } else {
            if(diff!=c){
                cout << "-1\n";
                return;
            }
        }
    }
    if(c==-1 || noDecr || m==-1) {
        cout << "0\n";
        return;
    }
    bool ok = true;
    for(int i = 1; i < n; i++){
        if(a[i-1]>=m || (a[i-1]+c)%m !=a[i]){
            ok = false;
            break;
        }
    }
    if(!ok || a[n-1]>=m) {
        cout << "-1\n";
        return;
    }
    cout << m << ' ' << c << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}