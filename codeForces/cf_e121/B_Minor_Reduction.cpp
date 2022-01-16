#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    for(int i = s.size() - 1; i > 0; i--){
        int sum = s[i] + s[i - 1] - '0' - '0';
        if(sum > 9){
            string num = to_string(sum);
            s[i - 1] = num[0];
            s[i] = num[1];
            cout << s << '\n';
            return;
        }
    }
    int sum = s[0] + s[1] - '0';
    cout << (char)sum;
    for(int i = 2; i < s.size(); i++){
        cout << s[i];
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}