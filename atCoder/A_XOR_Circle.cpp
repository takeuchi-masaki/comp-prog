#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        m[x]++;
    }
    // cout << m.size() << ' ' << m.begin()->first << ' ' << m.begin()->second << endl;
    // cout << m.end().operator--()->first << endl;
    bool ok = false;
    if(m.size() == 1 && m.begin()->first == 0){
        ok = true;
    } else if(n%3 == 0){
        if(m.size() == 2){
            if(m.begin()->first == 0 && m.end().operator--()->second == 2*n/3){
                ok = true;
            }
        } else if(m.size() == 3){
            bool allN3 = true;
            int xor_val = 0;
            for(pair<int, int> p:m){
                if(p.second != n/3){
                    allN3 = false;
                    break;
                }
                xor_val ^= p.first;
            }
            if(xor_val == 0 && allN3) ok = true;
        }
    }
    cout << (ok?"Yes\n":"No\n");
}