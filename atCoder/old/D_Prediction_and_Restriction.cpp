#include <bits/stdc++.h>
using namespace std;

int r, s, p;
char win(char c){
    switch(c){
        case 'r': return 'p';
        case 's': return 'r';
        case 'p': return 's';
    }
    return ' ';
}

int score(char c){
    switch(c){
        case 'r': return r;
        case 's': return s;
        case 'p': return p;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    cin >> r >> s >> p;
    string t; cin >> t;
    long long res = 0;
    vector<char> choice(n);
    for(int i = 0; i < k; i++){
        char c = t[i];
        char w = win(c);
        res+=score(w);
        choice[i]=w;
    }
    for(int i = k; i < n; i++){
        char c = t[i];
        char w = win(c);
        if(w!=choice[i-k]){
            choice[i]=w;
            res+=score(w);
        }
    }
    cout << res << '\n';
}