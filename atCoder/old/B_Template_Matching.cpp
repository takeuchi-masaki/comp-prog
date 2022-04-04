#include <bits/stdc++.h>
using namespace std;

int n, m; 

bool checkMatch(int startI, int startJ, vector<string> & a, vector<string> & b){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(a[startI + i][startJ + j] != b[i][j]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(string & s : a) cin >> s;
    for(string & s : b) cin >> s;
    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            if(checkMatch(i, j, a, b)) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}