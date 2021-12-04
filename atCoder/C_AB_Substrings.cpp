#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> vs(n);
    for(string & s : vs) cin >> s;
    long long total = 0, startB = 0, endA = 0, both = 0;
    for(string s : vs){
        if(s[0] == 'B') {
            startB++;
            if(s[s.size() - 1] == 'A') both++;
        }
        if(s[s.size() - 1] == 'A') endA++;
        
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == 'A'){
                if(s[i + 1] == 'B') total++;
            }
        }
    }
    long long add = min((long long)n - 1, min(startB, endA));
    total += add;
    if(both && startB == both && endA == both && min(startB, endA) < n) total--;
    cout << total << '\n';
}