#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int na, nb;
    cin >> na >> nb;
    int k, m;
    cin >> k >> m;

    vector<int> a(na), b(nb);
    for(int&i : a){
        cin >> i;
    }
    for(int&i : b){
        cin >> i;
    }
    // for(int i = 0; i < na; i++){
    //     cin >> a[i];
    // }
    // for(int i = 0; i < nb; i++){
    //     cin >> b[i];
    // }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a[k-1] < b[nb-m]){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}