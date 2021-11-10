#include <bits/stdc++.h>
using namespace std;

void printAns(bool ok){
    cout << (ok?"YES\n":"NO\n");
}

void solve(){
    int a, b; cin >> a >> b;
    if(a == 0 || b == 0){
        printAns(a == b);
        return;
    }
    int currB = a / 2, currA = b / 2;
    if(a&1) currB += 2;
    if(b&1) currA += 2;
    if(b < currB || a < currA) {
        printAns(false);
        return;
    }
    if( (b-currB) % 3 == 0 ) {
        printAns(true);
        return;
    }
    printAns(false);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("test_input.txt","r",stdin); freopen("user_output.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}