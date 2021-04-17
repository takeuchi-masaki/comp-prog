#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> prefix_AC(n+1);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='A'){
            if(s[i+1]=='C'){
                cnt++;
            }
        }
        prefix_AC[i+1]=cnt;
    }
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        cout << prefix_AC[r]-prefix_AC[l] << '\n';
    }
}