#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve(){
    int ROW, COL; cin >> ROW >> COL;
    string s; cin >> s;
    int n = s.size();
    int currI=0, currJ=0, prevI=0, prevJ=0;
    int maxI = 0, maxJ = 0, minI = 0, minJ = 0;
    
    for(int i = 0; i < n; i++){
        switch(s[i]){
            case 'L': currJ--; break;
            case 'R': currJ++; break;
            case 'U': currI--; break;
            case 'D': currI++; break;
        }
        int nextmaxI = max(maxI, currI);
        int nextmaxJ = max(maxJ, currJ);
        int nextminI = min(minI, currI);
        int nextminJ = min(minJ, currJ);
        if(nextmaxI - nextminI >= ROW || nextmaxJ-nextminJ >= COL) break;
        maxI = nextmaxI, maxJ = nextmaxJ, minI = nextminI, minJ = nextminJ;
        prevI = currI, prevJ = currJ;
    }
    // cout << minI << ' ' << maxI << '\n';
    // cout << minJ << ' ' << maxJ << '\n';
    int I, J;
    cout << ROW-maxI << ' ' << COL-maxJ << '\n';
    // cout << I << ' ' << J << '\n';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}