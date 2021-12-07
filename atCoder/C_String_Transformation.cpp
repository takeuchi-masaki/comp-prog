#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, t; cin >> s >> t;
    int n = s.size();
    const int NOT_USED = 99;
    vector<int> m(26, NOT_USED), mapped(26, NOT_USED);
    
    for(int i = 0; i < n; i++){
        if(m[s[i] - 'a'] == NOT_USED){
            if(mapped[t[i] - 'a'] != NOT_USED) {
                cout << "No\n";
                return 0;
            }
            m[s[i] - 'a'] = t[i] - 'a';
            mapped[t[i] - 'a'] = s[i] - 'a';
        } else if(m[s[i] - 'a'] != t[i] - 'a') {
            cout << "No\n";
            return 0;
        }
    }

    for(int i : m){
        if(i == NOT_USED){
            cout << "Yes\n";
            return 0;
        }
    }

    for(int i = 0; i < 26; i++){
        if(m[i] == i) continue;
        // m['a'] = 'i'
        // mapped['a'] = 'j'
        // m['j'] = 'a'
        m[mapped[i]] = m[i];
        mapped[m[i]] = mapped[i];

        m[i] = i;
        mapped[i] = i;
    }

    for(int i = 0; i < 26; i++){
        if(m[i] != i || mapped[i] != i){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}