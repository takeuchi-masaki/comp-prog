#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        cout << num << '\n';
        for(int i = 0; i < 4; i++){
            if(num>>i&1) cout << (1<<i) << ' ';
        }
        cout << '\n';
    }
}