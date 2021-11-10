#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<int> alpha_count(26);
    for(char c : s) alpha_count[c-'A']++;
    int odd = -1;
    for(int i = 0; i < 26; i++) {
        if(alpha_count[i]&1){
            if(odd != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd = i;
        }
    }
    string a = "", o = "";
    for(int i = 0; i < 26; i++){
        if(i == odd){
            o.push_back(i + 'A');
        }
        for(int cnt = 0; cnt < alpha_count[i]/2; cnt++){
            a.push_back(i + 'A');
        }
    }
    cout << a << o;
    reverse(a.begin(), a.end());
    cout << a << '\n';
}