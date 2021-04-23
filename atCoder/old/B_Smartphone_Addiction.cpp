#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok?"Yes\n":"No\n");
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, t; cin >> n >> m >> t;
    int capacity = n;
    int curr = 0;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        n-=(a-curr);
        if(n<=0) {
            ans(false);
            return 0;
        }
        n+=(b-a);
        if(n>capacity) n=capacity;
        curr = b;
    }
    n-=t-curr;
    if(n<=0){
        ans(false);
    } else {
        ans(true);
    }
}