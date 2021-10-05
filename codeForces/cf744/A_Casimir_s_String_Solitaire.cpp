#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> letter(3, 0);
    for(int i = 0; i < n; i++){
        letter[ s[i]-'A' ]++;
    }
    if(letter[1] == n/2 && letter[0]+letter[2] == letter[1]){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}