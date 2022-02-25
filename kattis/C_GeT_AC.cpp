#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> prefix(n + 1);
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1];
        if(s[i - 1] == 'A' && s[i] == 'C') prefix[i]++;
    }

    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        cout << prefix[b] - prefix[a] << '\n';
    }
}