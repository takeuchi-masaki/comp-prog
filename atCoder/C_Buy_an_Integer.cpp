#include <bits/stdc++.h>
using namespace std;
long long a, b, x;

int digits(int n){
    int cnt = 0;
    while(n>0){
        n/=10;
        cnt++;
    }
    return cnt;
}

bool ok(int n){
    long long res = a*n + digits(n)*b;
    return res>x;
}

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> a >> b >> x;
    // a*n + digits(n)*b
    if(x < a + b) {
        cout << "0\n";
        return 0;
    }

    int l = 1, r = 1e9+1;
    while(r-l>1){
        int mid = l + (r-l)/2;
        if(ok(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << '\n';
}