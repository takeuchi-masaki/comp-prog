#include <bits/stdc++.h>
using namespace std;

// make last numbers 25, 50, 75, or 00
string s;
int n;

int remove(char find1, char find2){
    int first = -1, second = -1;
    for(int i = n-1; i >= 0; i--){
        if(first == -1 && s[i] == find1) first = i;
        else if(first != -1 && second == -1 && s[i] == find2) second = i;
    }
    if(first != -1 && second != -1){
        // cout << find2 << find1 << '\n';
        // cout << first << ' ' << second << '\n';
        return (n-1-first) + (first-1-second);
    }
    return 1e9;
}

void solve(){
    cin >> s;
    n = s.size();

    int find00 = remove('0', '0'),
        find25 = remove('5', '2'),
        find50 = remove('0', '5'),
        find75 = remove('5', '7');
    cout << min(min(find00, find25), min(find50, find75)) << '\n';
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}