#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int&i:a){
        cin >> i;
    }
    for(int&i:b){
        cin >> i;
    }
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += a[i]*b[i];
    }
    cout << (res==0?"Yes\n":"No\n");
}