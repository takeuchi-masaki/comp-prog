#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool ok = true, adj0 = false, adj1 = false;
        int n = s.length();
        for(int i = 0; i < n-1; i++){
            if(s[i]==s[i+1]){
                if(s[i]=='0'){
                    adj0 = true;
                    if(adj1) {
                        ok = false;
                        break;
                    }
                } else {
                    adj1 = true;
                }
            }
        }
        cout << (ok?"YES":"NO") << endl;
    }
}